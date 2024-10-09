#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QWheelEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isModified(false)
    , zoomFactor(1.0)  // 初始化缩放比例为1.0（默认比例）
{
    ui->setupUi(this);

    // 创建 QLabel 用于显示字数，并添加到 statusBar 的右边
    wordCountLabel = new QLabel(this);
    ui->statusbar->addPermanentWidget(wordCountLabel);  // 将 QLabel 固定在状态栏右边
    // 初始化字数统计标签
    wordCountLabel->setText("字数: 0");

    // 连接 QTextEdit 的 textChanged() 信号到更新字数的槽函数
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::updateWordCount);
    connect(ui->textEdit,&QTextEdit::textChanged,this,[this](){
        isModified = true;
    });
//    connect(ui->newpage, &QAction::triggered, this, &MainWindow::on_actionNew_triggered);
    connect(ui->action_16, &QAction::triggered, this, &MainWindow::on_action_16_triggered);
    connect(ui->action_17, &QAction::triggered, this, &MainWindow::on_action_17_triggered);
    connect(ui->action_18, &QAction::triggered, this, &MainWindow::on_action_18_triggered);
    connect(ui->action_Y, &QAction::triggered, this, &MainWindow::on_action_Y_triggered);  // 撤销
    connect(ui->action_X, &QAction::triggered, this, &MainWindow::on_action_X_triggered);  // 剪切
    connect(ui->action_C, &QAction::triggered, this, &MainWindow::on_action_C_triggered);  // 复制
    connect(ui->action_V, &QAction::triggered, this, &MainWindow::on_action_V_triggered);  // 粘贴
    connect(ui->action_D, &QAction::triggered, this, &MainWindow::on_action_D_triggered);  // 删除
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::showHelp);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::showVersion);
    // 连接 QAction 到用于切换字数统计显示的槽函数
    connect(ui->action_20, &QAction::triggered, this, &MainWindow::toggleWordCountVisibility);
    setWindowTitle("NotepadPlus");

    resize(800,600);
    ui->statusbar->setStyleSheet("QStatusBar {"
                                 "background: transparent;"         // 背景无颜色
                                 "color: black;"                    // 字体颜色
                                 /*"font-family: 'SimSun';"*/           // 字体设置为宋体
                                 "font-size: 14px;"                 // 字体大小
                                 "border: none;"                    // 无边框
                                 "}");

    // 显示消息
    ui->statusbar->showMessage("欢迎使用 NotepadPlus");



}

MainWindow::~MainWindow()
{
    delete ui;
}

// 更新字数统计的槽函数
void MainWindow::updateWordCount()
{
    // 获取 QTextEdit 中的文本
    QString text = ui->textEdit->toPlainText();

    // 计算字数
    int wordCount = text.length();

    // 更新字数显示
    wordCountLabel->setText("字数: " + QString::number(wordCount));
}
// 显示/隐藏字数统计的槽函数
void MainWindow::toggleWordCountVisibility()
{
    // 切换字数标签的可见性
    wordCountLabel->setVisible(!wordCountLabel->isVisible());
}


// 检查是否有未保存的更改
void MainWindow::checkForUnsavedChanges()
{
    if (isModified) {
        // 如果内容已修改，弹出提示框，询问用户是否保存
        QMessageBox::StandardButton reply = QMessageBox::question(this, "保存更改",
                                                                  "当前文件尚未保存，是否保存？",
                                                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            // 如果用户选择保存，则调用保存函数（这里假设有 save 功能）
            saveFile();
        } else if (reply == QMessageBox::Cancel) {
            // 如果用户选择取消，则终止新建操作
            return;
        }
    }
}

// 保存文件的功能实现
void MainWindow::saveFile()
{
    // 打开文件对话框，选择保存位置和文件名
      QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "", "文本文件 (*.txt);;所有文件 (*)");

      // 检查用户是否选择了文件名
      if (!fileName.isEmpty()) {
          QFile file(fileName);
          // 尝试打开文件进行写入
          if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
              QTextStream out(&file);
              out << ui->textEdit->toPlainText();  // 将文本编辑区的内容写入文件
              file.close();  // 关闭文件
              isModified = false;  // 重置已修改状态
          } else {
              // 如果文件无法打开，显示错误提示
              QMessageBox::warning(this, "保存错误", "无法保存文件。");
          }
      }
}

// 实现“新建”功能的槽函数
void MainWindow::on_newpage_triggered()
{
    // 检查当前内容是否已修改，并提示保存
    checkForUnsavedChanges();

    // 清空编辑区
    ui->textEdit->clear();

    // 重置已修改状态
    isModified = false;
}

void MainWindow::on_open_triggered()
{
    // 检查是否有未保存的更改
        if (isModified) {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "保存更改",
                                                                      "当前文件尚未保存，是否保存？",
                                                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

            if (reply == QMessageBox::Yes) {
                on_save_triggered();  // 调用保存功能
            } else if (reply == QMessageBox::Cancel) {
                return;  // 用户选择取消，终止打开文件操作
            }
        }

        // 打开文件对话框，选择文件
        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "", "文本文件 (*.txt);;所有文件 (*)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                ui->textEdit->setPlainText(in.readAll());  // 读取文件内容
                file.close();  // 关闭文件
                currentFile = fileName;  // 设置当前文件名
                isModified = false;  // 重置已修改状态
            } else {
                QMessageBox::warning(this, "打开错误", "无法打开文件。");
            }
        }
}

void MainWindow::on_save_triggered()
{
    // 如果当前没有打开的文件，使用保存对话框选择文件名
        if (currentFile.isEmpty()) {
            currentFile = QFileDialog::getSaveFileName(this, "保存文件", "", "文本文件 (*.txt);;所有文件 (*)");
            if (currentFile.isEmpty()) {
                return;  // 用户取消保存
            }
        }
        // 尝试打开文件进行写入
        QFile file(currentFile);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();  // 将文本编辑区的内容写入文件
            file.close();  // 关闭文件
            isModified = false;  // 重置已修改状态
        } else {
            // 如果文件无法打开，显示错误提示
            QMessageBox::warning(this, "保存错误", "无法保存文件。");
        }
}

// 另存为
void MainWindow::on_saveas_triggered()
{
    // 获取文件路径
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) {
        return;
    }
    // 打开文件进行写操作
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("错误"), tr("无法保存文件: %1").arg(file.errorString()));
        return;
    }
    // 使用 QTextStream 写入文本内容
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    currentFile = fileName;
    setWindowTitle(fileName);
}
void MainWindow::on_exit_triggered()
{
    // 检查是否有未保存的更改
        if (isModified) {
            // 如果内容已修改，弹出提示框，询问用户是否保存
            QMessageBox::StandardButton reply = QMessageBox::question(this, "保存更改",
                                                                      "当前文件尚未保存，是否保存？",
                                                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

            if (reply == QMessageBox::Yes) {
                // 如果用户选择保存，调用保存文件的函数
                saveFile();
                qApp->quit();  // 退出应用程序
            } else if (reply == QMessageBox::No) {
                // 如果用户选择不保存，直接退出
                qApp->quit();
            } else if (reply == QMessageBox::Cancel) {
                // 如果用户选择取消，则终止退出操作
                return;
            }
        } else {
            // 如果没有未保存的更改，直接退出
            qApp->quit();
        }
}




void MainWindow::on_action_Y_triggered() // 撤销操作
{
    ui->textEdit->undo();  // 调用文本编辑器的撤销功能
}

void MainWindow::on_action_X_triggered() // 剪切操作
{
    ui->textEdit->cut();  // 调用剪切功能，将选中的文本剪切到剪贴板
}

void MainWindow::on_action_C_triggered() // 复制操作
{
    ui->textEdit->copy();  // 调用复制功能，将选中的文本复制到剪贴板
}


void MainWindow::on_action_V_triggered() // 粘贴操作
{
    ui->textEdit->paste();  // 调用粘贴功能，将剪贴板内容粘贴到光标位置
}


void MainWindow::on_action_D_triggered() // 删除操作
{
    ui->textEdit->textCursor().removeSelectedText();  // 删除当前选中的文本
}




//// 放大功能实现
//void MainWindow::on_action_16_triggered()
//{
//    zoomFactor += 0.1;  // 增加缩放比例
//    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
//    ui->textEdit->selectAll();  // 选中所有文本
//    ui->textEdit->setFontPointSize(12 * zoomFactor);  // 按比例调整字体大小
//    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
//}

//// 缩小功能实现
//void MainWindow::on_action_17_triggered()
//{
//    zoomFactor -= 0.1;  // 减少缩放比例
//    if (zoomFactor < 0.1) {
//        zoomFactor = 0.1;  // 确保缩放比例不会太小
//    }
//    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
//    ui->textEdit->selectAll();  // 选中所有文本
//    ui->textEdit->setFontPointSize(12 * zoomFactor);  // 按比例调整字体大小
//    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
//}

//// 恢复默认缩放功能实现
//void MainWindow::on_action_18_triggered()
//{
//    zoomFactor = 1.0;  // 重置缩放比例
//    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
//    ui->textEdit->selectAll();  // 选中所有文本
//    ui->textEdit->setFontPointSize(12);  // 恢复默认字体大小
//    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
//}





// 放大功能实现
void MainWindow::on_action_16_triggered()
{
    zoomFactor += 0.1;  // 增加缩放比例
    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
    ui->textEdit->selectAll();  // 选中所有文本
    ui->textEdit->setFontPointSize(12 * zoomFactor);  // 按比例调整字体大小
    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
}

// 缩小功能实现
void MainWindow::on_action_17_triggered()
{
    zoomFactor -= 0.1;  // 减少缩放比例
    if (zoomFactor < 0.1) {
        zoomFactor = 0.1;  // 确保缩放比例不会太小
    }
    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
    ui->textEdit->selectAll();  // 选中所有文本
    ui->textEdit->setFontPointSize(12 * zoomFactor);  // 按比例调整字体大小
    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
}

// 恢复默认缩放功能实现
void MainWindow::on_action_18_triggered()
{
    zoomFactor = 1.0;  // 重置缩放比例
    QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
    ui->textEdit->selectAll();  // 选中所有文本
    ui->textEdit->setFontPointSize(12);  // 恢复默认字体大小
    ui->textEdit->setTextCursor(cursor);  // 恢复光标位置
}

// 处理滚轮缩放事件
void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {  // 检查 Ctrl 键是否按下
        if (event->angleDelta().y() > 0) {
            zoomFactor += 0.1;  // 向上滚动放大
        } else {
            zoomFactor -= 0.1;  // 向下滚动缩小
            if (zoomFactor < 0.1) {
                zoomFactor = 0.1;  // 确保缩放比例不会太小
            }
        }
        QTextCursor cursor = ui->textEdit->textCursor();  // 保存当前光标位置
        ui->textEdit->selectAll();  // 选中所有文本
        ui->textEdit->setFontPointSize(12 * zoomFactor);  // 按比例调整字体大小
        ui->textEdit->setTextCursor(cursor);  // 恢复光标位置

        event->accept();  // 接受事件，防止其被其他部件处理
    } else {
        QMainWindow::wheelEvent(event);  // 调用父类的默认处理
    }
}

void MainWindow::showHelp()
{
    QMessageBox::information(this, "说明", "缩放功能请使用Ctrl+鼠标滚轮。");
}

void MainWindow::showVersion()
{
    QMessageBox::information(this, "版本", "版本 1.0.0\n开发者: 小李");
}
