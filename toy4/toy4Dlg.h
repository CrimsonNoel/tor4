
// toy4Dlg.h : ��� ����
//

#pragma once
#include <vector>
using namespace std;
// Ctoy4Dlg ��ȭ ����
class Ctoy4Dlg : public CDialogEx
{
	// �����Դϴ�.
public:
	Ctoy4Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// Ŀ���� ����
private:
	FILE* file;
	CString szFilter;
	CString result;
public:
	void Average(vector<int>& arr,CString& res);//��ձ��ϱ�

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY4_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonWrite();
};

class Print1 : public Ctoy4Dlg
{
private:
public:
	void PAverage(vector<int>& arr,CString& res);
};
