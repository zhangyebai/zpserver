﻿#ifndef MAINWNDCTRLPANNEL_H
#define MAINWNDCTRLPANNEL_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "dialoglogin.h"
#include "dialogsettings.h"
#include "qcoloriconsqlmodel.h"
namespace Ui {
	class mainwndCtrlPannel;
}

class mainwndCtrlPannel : public QMainWindow
{
	Q_OBJECT

public:
	explicit mainwndCtrlPannel(QWidget *parent = 0);
	~mainwndCtrlPannel();

protected:
	void changeEvent(QEvent *e);
	void timerEvent(QTimerEvent * e);
	DialogSettings * m_pSettingsDlg;
	DialogLogin * m_pLoginDlg;
	QColorIconSqlModel * m_pModel_Summary_PK;
	QColorIconSqlModel * m_pModel_Summary_MAC;
	QColorIconSqlModel * m_pModel_Summary_DEV;
	QColorIconSqlModel * m_pModel_Detail;
	QColorIconSqlModel * m_pModel_EvtHis;
	QColorIconSqlModel * m_pModel_MacHis;
	QColorIconSqlModel * m_pModel_Express_DEV;
private:
	int m_nTimer;
	Ui::mainwndCtrlPannel *ui;
	QSqlDatabase m_db;
	bool login();
	void UpdateIconAndColors();
	void ui_pntf(const char * pFmt,...);

	void LoadSettings();
	void SaveSettings();

public slots:
	void on_actionExit_triggered();
	void on_actionConfig_triggered();
	void on_action_Connect_triggered(bool);
	void on_action_About_triggered();
	void on_action_Refresh_triggered();
	void on_actionAdvanced_Function_triggered(bool);
	//Modify
	void on_actionManage_Users_triggered();
	void on_actionManage_Parkinglots_triggered();
	void on_actionManage_MACs_triggered();
	void on_actionManage_Devices_triggered();
	void on_actionParkinglots_and_users_triggered();
	void on_actionMac_and_Parkinglots_triggered();

	//User clicked
	void on_listView_sum_pklts_doubleClicked(const QModelIndex & index);
	void on_listView_sum_macs_doubleClicked(const QModelIndex & index);
	void on_listView_sum_devices_doubleClicked(const QModelIndex & index);
	void on_tableView_detailed_doubleClicked(const QModelIndex & index);
	//Ctrl Messages, get info
	void on_pushButton_getMacInfo_clicked();
	void on_pushButton_getDevList_clicked();
	void on_pushButton_getDevPara_clicked();
	//Ctrl Messages, command
	void on_pushButton_setMacInfo_clicked();
	void on_pushButton_setDevInfo_clicked();
	void on_pushButton_removeDev_clicked();

	//Ctrl Messages, Update firmware
	void on_toolButton_brff_clicked();
	void on_pushButton_runfu_clicked();
	//DAL
	void on_pushButton_dalctrl_clicked();
	//Send DAL
	void on_actionReset_Selected_Devices_triggered();
};

#endif // MAINWNDCTRLPANNEL_H
