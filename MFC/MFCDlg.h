
// MFCDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCDlg
class CMFCDlg : public CDialogEx
{
// Создание
public:
	CMFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtTimerstart();
	CProgressCtrl _Progress_Time;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int _Time;
	afx_msg void OnBnClickedBtadd();
	CSpinButtonCtrl _Sum_dolg;
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	CStatic _St_sum_dolg;
	CListBox _List_dolg;

	CEdit _Name_dolg;
	afx_msg void OnBnClickedBtdelete();
	CButton _Check1;
	CButton _Check2;
	CButton _Check3;
	CButton _Check4;
	CButton Check5;
	afx_msg void OnBnClickedButton4();
	CComboBox _Title;
	afx_msg void OnCbnSelchangeCombo6();
	CButton _Name_1;
	CButton _Name_2;
	CButton _Name_3;
	afx_msg void OnBnClickedButton5();
	bool MyName(int x);
	CStatic _MyName;
	void SmthBad();
	afx_msg void OnLbnSelchangeList2();
};
