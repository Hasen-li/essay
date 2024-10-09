#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void wheelEvent(QWheelEvent *event) override;  // 重写鼠标滚轮事件
private slots:
    void updateWordCount();  // 用于更新字数统计

    void on_newpage_triggered();

    void on_open_triggered();

    void on_save_triggered();

    void on_saveas_triggered();

    void on_exit_triggered();

    void on_action_16_triggered();  // 放大
    void on_action_17_triggered();  // 缩小
    void on_action_18_triggered();  // 恢复默认缩放
    void on_action_Y_triggered();  // 撤销
    void on_action_X_triggered();  // 剪切
    void on_action_C_triggered();  // 复制
    void on_action_V_triggered();  // 粘贴
    void on_action_D_triggered();  // 删除
    void showHelp();
    void showVersion();
    void toggleWordCountVisibility();

private:
    Ui::MainWindow *ui;
    QLabel *wordCountLabel;  // 用于显示字数的 QLabel
    QString currentFile;  // 当前打开的文件名
    bool isModified;
    void checkForUnsavedChanges();   // 提示保存未保存的内容（可选）
    void saveFile();
    double zoomFactor;  // 缩放比例变量

};
#endif // MAINWINDOW_H
