﻿#include <QMenu>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <qdrawutil.h>
#include <QPainter>
#include "MuTableManageMenu.h"

MuTableRightButtonMenu::MuTableRightButtonMenu(QWidget *parent)
    : MuShadowWindow<QWidget>(false, 10, parent)
{
    titleBar()->hide();
    setTitleBarHeight(0);
//    setModal(false);
    createMainWidget();
    setClientWidget(m_pMenu);
}

void MuTableRightButtonMenu::createMainWidget()
{
    m_pMenu = new QMenu(this);
    m_pViewCommentsAc = new QAction(tr("View All Comments(1234)"));
    m_pPlayAc = new QAction(tr("Play"));
    m_pNextSongAc = new QAction(tr("Play Next"));
    m_pAddToPlaylistAc = new QAction(tr("Add To Playlist"));
    m_pShareAc = new QAction(tr("Share"));
    m_pCopyLkAdAc = new QAction(tr("Copy Link Address"));
    m_pUpToMyCloudAc = new QAction(tr("Upload To My Cloud"));
    m_pOpenFolderAc = new QAction(tr("Open Folder"));
    m_pDeleteFromListAc = new QAction(tr("Delete From List"));
    m_pDeleteFromDiskAc = new QAction(tr("Delete From Disk"));

//    switch (m_tableType) {
//    case LocalTable:
        m_pMenu->addAction(m_pViewCommentsAc);
        m_pMenu->addAction(m_pPlayAc);
        m_pMenu->addAction(m_pNextSongAc);
        m_pMenu->addSeparator();
        m_pMenu->addAction(m_pAddToPlaylistAc);
        m_pMenu->addAction(m_pShareAc);
        m_pMenu->addAction(m_pCopyLkAdAc);
        m_pMenu->addAction(m_pUpToMyCloudAc);
        m_pMenu->addAction(m_pOpenFolderAc);
        m_pMenu->addSeparator();
        m_pMenu->addAction(m_pDeleteFromListAc);
        m_pMenu->addAction(m_pDeleteFromDiskAc);
//        break;
//    default:
//        break;
//    }
}

MuTableManageMenu::MuTableManageMenu(TableType table, QWidget *parent)
    : m_tableType(table)
    , QMenu(parent)
{
    setWindowFlags(windowFlags() | Qt::NoDropShadowWindowHint);
    setObjectName("tableManageMenu");
    createMainWidget();

    QGraphicsDropShadowEffect *pShadow = new QGraphicsDropShadowEffect(this);
    pShadow->setOffset(0, 0);
    pShadow->setColor(QColor("#cccccc"));
    pShadow->setBlurRadius(10);
    setGraphicsEffect(pShadow);

    connect(this, &MuTableManageMenu::triggered, [](QAction *action) {
        qDebug() << action;
    });
    connect(this, &MuTableManageMenu::aboutToHide, []() {
        qDebug() << "action";
    });
}

void MuTableManageMenu::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QMargins margin(2, 2, 2, 2);
    QPixmap pixMap(":/images/client-shadow.png");
    QRect rect();
    qDrawBorderPixmap(&painter, this->rect(), margin, pixMap);
    return QMenu::paintEvent(e);
}

void MuTableManageMenu::createMainWidget()
{
    m_pViewCommentsAc = new QAction(tr("View All Comments(1234)"));
    m_pPlayAc = new QAction(tr("Play"));
    m_pNextSongAc = new QAction(tr("Play Next"));
    m_pAddToPlaylistAc = new QAction(tr("Add To Playlist"));
    m_pShareAc = new QAction(tr("Share"));
    m_pCopyLkAdAc = new QAction(tr("Copy Link Address"));
    m_pUpToMyCloudAc = new QAction(tr("Upload To My Cloud"));
    m_pOpenFolderAc = new QAction(tr("Open Folder"));
    m_pDeleteFromListAc = new QAction(tr("Delete From List"));
    m_pDeleteFromDiskAc = new QAction(tr("Delete From Disk"));

    switch (m_tableType) {
    case LocalTable:
        this->addAction(m_pViewCommentsAc);
        this->addAction(m_pPlayAc);
        this->addAction(m_pNextSongAc);
        this->addSeparator();
        this->addAction(m_pAddToPlaylistAc);
        this->addAction(m_pShareAc);
        this->addAction(m_pCopyLkAdAc);
        this->addAction(m_pUpToMyCloudAc);
        this->addAction(m_pOpenFolderAc);
        this->addSeparator();
        this->addAction(m_pDeleteFromListAc);
        this->addAction(m_pDeleteFromDiskAc);
        break;
    default:
        break;
    }
}


//MuTableRightButtonMenu::MuTableRightButtonMenu(QWidget *parent)
//{

//}
