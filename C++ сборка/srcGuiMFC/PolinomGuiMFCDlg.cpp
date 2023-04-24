
// PolinomGuiMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PolinomGuiMFC.h"
#include "PolinomGuiMFCDlg.h"
#include "afxdialogex.h"

#include "Polinom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPolinomMain dialog



CPolinomMain::CPolinomMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POLINOMGUIMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPolinomMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPolinomMain, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDRUN, &CPolinomMain::OnBnClickedRun)
END_MESSAGE_MAP()


// CPolinomMain message handlers

BOOL CPolinomMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPolinomMain::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPolinomMain::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPolinomMain::OnBnClickedRun()
{
    if(cbOperation->currentIndex() == POLINOMS_ADD) // Polinom + Polinom
    {
        Polinom p1(ui.edOp1->text().trimmed().toStdString());
        Polinom p2(ui.edOp2->text().trimmed().toStdString());
        Polinom pres = p1 + p2;
        QString sres = ui.edOp1->text().trimmed() + "+";
        sres += ui.edOp2->text().trimmed() + " = ";
        sres += QString(pres.GivePolinom().c_str());
        ui.teResult->append(sres);
    }
    else if(ui.cbOperation->currentIndex() == POLINOMS_SUBS) // Polinom - Polinom
    {
        Polinom p1(ui.edOp1->text().trimmed().toStdString());
        Polinom p2(ui.edOp2->text().trimmed().toStdString());
        Polinom pres = p1 - p2;
        QString sres = ui.edOp1->text().trimmed() + "-(";
        sres += ui.edOp2->text().trimmed() + ") = ";
        sres += QString(pres.GivePolinom().c_str());
        ui.teResult->append(sres);
    }
}
