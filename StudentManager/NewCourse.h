﻿#pragma once
#include "afxdialogex.h"


// NewCourse 对话框

class NewCourse : public CDialogEx
{
	DECLARE_DYNAMIC(NewCourse)

public:
	NewCourse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewCourse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};
