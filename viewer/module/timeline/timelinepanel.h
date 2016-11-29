#ifndef TIMELINEPANEL_H
#define TIMELINEPANEL_H

#include "module/modulepanel.h"

class QLabel;
class QStackedWidget;
class PopupMenuManager;
class Slider;
class TimelineFrame;

class TimelinePanel : public ModulePanel
{
    Q_OBJECT
public:
    explicit TimelinePanel(QWidget *parent = 0);

    bool isMainPanel() Q_DECL_OVERRIDE;
    QString moduleName() Q_DECL_OVERRIDE;
    QWidget *extensionPanelContent() Q_DECL_OVERRIDE;
    QWidget *toolbarBottomContent() Q_DECL_OVERRIDE;
    QWidget *toolbarTopLeftContent() Q_DECL_OVERRIDE;
    QWidget *toolbarTopMiddleContent() Q_DECL_OVERRIDE;

protected:
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void showPanelEvent(ModulePanel *p) Q_DECL_OVERRIDE;

private:
    void initConnection();
    void initImagesView();
    void initMainStackWidget();
    void initShortcut();
    void initStyleSheet();
    void updateBottomToolbarContent(int count);
    void onImageCountChanged(int count);
    QJsonObject createAlbumMenuObj();
    void popupDelDialog(const QStringList &paths);
    void rotateImage(const QString &path, int degree);
    //Timeline menu
    void showMenuContext(QPoint pos);
    void onMenuItemClicked(int menuId, const QString &text);
private:
    QLabel              *m_countLabel;
    QStackedWidget      *m_mainStack;
    Slider              *m_slider;
    TimelineFrame       *m_frame;

    QStringList         m_rotateList;
};

#endif // TIMELINEPANEL_H
