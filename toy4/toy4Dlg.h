
// toy4Dlg.h : 헤더 파일
//

#pragma once
#include <vector>
using namespace std;
// Ctoy4Dlg 대화 상자
class Ctoy4Dlg : public CDialogEx
{
	// 생성입니다.
public:
	Ctoy4Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 커스텀 생성
private:
	FILE* file;
	CString szFilter;
	CString result;
public:
	void Average(vector<int>& arr,CString& res);//평균구하기

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY4_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
