
// MFCDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC.h"
#include "MFCDlg.h"
#include "afxdialogex.h"
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int Pos_Timer = 0;
int HowMany = 0;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCDlg



CMFCDlg::CMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
	, _Time(0)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_Timer, _Progress_Time);
	DDX_Text(pDX, IDC_EDIT_Timer, _Time);
	DDX_Text(pDX, IDC_EDIT_Timer, _Time);
	DDX_Control(pDX, IDC_SPIN1, _Sum_dolg);
	DDX_Control(pDX, IDC_STATIC_Sum_dolg, _St_sum_dolg);
	DDX_Control(pDX, IDC_LIST2, _List_dolg);

	DDX_Control(pDX, IDC_EDIT2, _Name_dolg);
	DDX_Control(pDX, IDC_CHECK1, _Check1);
	DDX_Control(pDX, IDC_CHECK3, _Check2);
	DDX_Control(pDX, IDC_CHECK4, _Check3);
	DDX_Control(pDX, IDC_CHECK5, _Check4);
	DDX_Control(pDX, IDC_CHECK6, Check5);
	DDX_Control(pDX, IDC_COMBO6, _Title);
	DDX_Control(pDX, IDC_RADIO3, _Name_1);
	DDX_Control(pDX, IDC_RADIO4, _Name_2);
	DDX_Control(pDX, IDC_RADIO5, _Name_3);
	DDX_Control(pDX, IDC_STATIC_, _MyName);
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_TimerStart, &CMFCDlg::OnBnClickedBtTimerstart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTAdd, &CMFCDlg::OnBnClickedBtadd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFCDlg::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BTDelete, &CMFCDlg::OnBnClickedBtdelete)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCDlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CMFCDlg::OnCbnSelchangeCombo6)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCDlg

BOOL CMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	_Sum_dolg.SetRange(1, 10);

	_Title.AddString(L"Восхитительное приложение!");
	_Title.AddString(L"Лучшее приложение!");
	_Title.AddString(L"Боже мой! Чудесное приложение!");
	_Title.AddString(L"Это вообще не то...");
	_Title.AddString(L"Замечательно приложение!");
	
	int countItem = _Title.GetCount();
	for (int i = 0; i < countItem; i++)
		_Title.DeleteString(0);

	_Title.AddString(L"AOAOAOOAO");
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDlg::OnBnClickedBtTimerstart()
{
	UpdateData(TRUE);

	_Progress_Time.SetRange(0, _Time);

	_Progress_Time.SetPos(0);

	Pos_Timer = 0;
	SetTimer(1, 1000, 0);
	SmthBad();
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	Pos_Timer++;
	if (Pos_Timer > _Time) {
		KillTimer(1);
		int yes_no_time = AfxMessageBox(L"ВРЕМЯ ВЫШЛО!!\nПовторить?", MB_YESNO);
		if (yes_no_time == IDYES)
			CMFCDlg::OnBnClickedBtTimerstart();
		Pos_Timer = 0;
		_Progress_Time.SetPos(0);
	}

	_Progress_Time.SetPos(Pos_Timer);

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCDlg::OnBnClickedBtadd()
{
	CString str1, str2, str;
	str2.Format(L" должен %i $", _Sum_dolg.GetPos32() - 1);
	_Name_dolg.GetWindowTextW(str1);
	str = str1 + str2;
	_List_dolg.AddString(str);
	_Sum_dolg.SetPos(1);
	SmthBad();
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	CString str;
	str.Format(L"%d", _Sum_dolg.GetPos32());
	_St_sum_dolg.SetWindowTextW(str);
	*pResult = 0;
}


void CMFCDlg::OnBnClickedBtdelete()
{
	MessageBox(L"Должник однажды Должник навсегда!!");
	SmthBad();
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCDlg::OnBnClickedButton4()
{
	if (_Check1.GetCheck() == 1 && _Check2.GetCheck() == 0 && _Check3.GetCheck() == 0 &&
		_Check4.GetCheck() == 1 && Check5.GetCheck() == 0)
		MessageBox(L"ВАУ! Все верно. Молодец!");
	else MessageBox(L"УПС. Думаю что-то не так");
	SmthBad();
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCDlg::OnCbnSelchangeCombo6()
{
	CString Title;
	_Title.GetLBText(_Title.GetCurSel(), Title);
	CDialog::SetWindowTextW(Title);
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCDlg::OnBnClickedButton5()
{
	// TODO: добавьте свой код обработчика уведомлений

	if (_Name_1.GetCheck() == 1) {
		HowMany++;
		if (MyName(HowMany) != true)
			MessageBox(L"Почти верно!");
	}
	if (_Name_2.GetCheck() == 1) {
		HowMany++;
		if (MyName(HowMany) != true);
			MessageBox(L"Все еще не совсем, но близно!");
	}
	if (_Name_3.GetCheck() == 1) {
		HowMany++;
		if (MyName(HowMany) != true)
			MessageBox(L"Почти же..");
	}
	SmthBad();
}

bool CMFCDlg::MyName(int x) {
	if (x >= 3) {
		MessageBox(L"На самом деле я сама не знаю как точно. Хехе\nНо пусть будет Iuliia");
		CString str;
		str = "Iuliia";
		_MyName.SetWindowTextW(str);
		return true;
	}
	return false;
}

void CMFCDlg::SmthBad() {
	srand(time(0));
	int ww = 1 + rand() % 7;
	if (ww == 3)
		MessageBox(L"Мне кажется я делала что-то не то...");

}
