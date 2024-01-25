
// toy4Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "toy4.h"
#include "toy4Dlg.h"
#include "afxdialogex.h"
#include "vector"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctoy4Dlg ��ȭ ����



Ctoy4Dlg::Ctoy4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TOY4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctoy4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctoy4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Read, &Ctoy4Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Write, &Ctoy4Dlg::OnBnClickedButtonWrite)
END_MESSAGE_MAP()


// Ctoy4Dlg �޽��� ó����

BOOL Ctoy4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.


	szFilter = "�ؽ�Ʈ����(*.txt) |*.txt| �������(*.*) |*.*||";


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Ctoy4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Ctoy4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Ctoy4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctoy4Dlg::OnBnClickedButtonRead()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString path;
	vector<int> arrInt;
	vector<CString> arrString;
	CFileDialog fDlg(TRUE, "txt", "", OFN_HIDEREADONLY, szFilter);

	if (IDOK == fDlg.DoModal())
	{
		path = fDlg.GetPathName();
		AfxMessageBox("���ã�� ����");

		//���� ���� // �ؽ�Ʈ���� �б� ���
		errno_t ReadFile = fopen_s(&file, path, "rt");
		//���� ������� �� ���� Ȯ���ϱ�
		if (ReadFile == 0)
		{
			AfxMessageBox("���Ͽ��� ����");
			char str[100];
			while (fgets(str, sizeof(str) + 1, file) != NULL)
			{
				if (str[strlen(str) - 1] == '\n')
					str[strlen(str) - 1] = '\0';

				bool isNum = TRUE;
				for (int i = 0; i < strlen(str); i++)
				{
					char c = str[i];
					if (isdigit(c) == 0)
					{
						isNum = FALSE;
						break;
					}
				}
				if (isNum == TRUE)
				{
					int num = atoi(str);
					CString nums;
					nums.Format("%d", num);
					if (strcmp(str, nums) == 0)
					{
						arrInt.push_back(num);
					}
					else
					{
						arrString.push_back(str);
					}
				}
				else
				{
					arrString.push_back(str);
				}
			}

			/*for (int i = 0; i < arrInt.size(); i++)
			{
				CString nums;
				nums.Format("%d", arrInt[i]);
				AfxMessageBox(nums);
			}*/
		}
		else
		{	// ���� ���� ���������� ����
			// Ȯ��..?
			char errormsg[100];
			strerror_s(errormsg, sizeof(errormsg) + 1, ReadFile);
			AfxMessageBox(errormsg);
		}
		//��հ� ���ϱ�
		//Average(arrInt, result);
		Print1 p1;
		p1.PAverage(arrInt, result);
		AfxMessageBox(result);
	}


	SetDlgItemText(IDC_EDIT_ReadPath, path); // path IDC_EDIT_ReadPath�� ���
	SetDlgItemText(IDC_EDIT_Average, result); // ��հ� IDC_EDIT_Average�� ���
	fclose(file); // ���ϴݱ�
}


void Ctoy4Dlg::OnBnClickedButtonWrite()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString path;
	CFileDialog fDlg(FALSE, "txt", "", OFN_HIDEREADONLY, szFilter);
	//AfxMessageBox(result);
	if (IDOK == fDlg.DoModal())
	{
		path = fDlg.GetPathName(); // �������
	}
	SetDlgItemText(IDC_EDIT_WritePath, path);
	//���� ����
	errno_t WriteOpen = fopen_s(&file, path, "wt");
	if (WriteOpen == 0)
	{
		fprintf(file, "��հ�: %s", result);
		AfxMessageBox("��� ����");
		fclose(file); // ���ϴݱ�
	}
}
void Ctoy4Dlg::Average(vector<int>& arr, CString& res)
{
	double sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	res.Format("%.2lf", sum /= arr.size());
	//AfxMessageBox(res);
}

void Print1::PAverage(vector<int>& arr, CString& res)
{
	double sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	res.Format("%.2lf", sum /= arr.size());
	//AfxMessageBox(res);
}