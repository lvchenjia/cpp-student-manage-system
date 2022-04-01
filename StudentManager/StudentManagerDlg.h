
// StudentManagerDlg.h: 头文件
//

#pragma once


// CStudentManagerDlg 对话框
class CStudentManagerDlg : public CDialogEx
{
// 构造
public:
	CStudentManagerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNewclass();
	afx_msg void OnBnClickedQueryclass();
	afx_msg void OnBnClickedNewstudent();
	afx_msg void OnBnClickedNewcourse();
	afx_msg void OnBnClickedQuerystudent();
	afx_msg void OnBnClickedDeleteclass();
	afx_msg void OnBnClickedDeltetestudent();
	afx_msg void OnBnClickedModifystudent();
	afx_msg void OnBnClickedModifymark();
	afx_msg void OnBnClickedQuerycourse();
};
