
// toy4.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Ctoy4App:
// �� Ŭ������ ������ ���ؼ��� toy4.cpp�� �����Ͻʽÿ�.
//

class Ctoy4App : public CWinApp
{
public:
	Ctoy4App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()

};

extern Ctoy4App theApp;