
// BackkomDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CBackkomDlg 对话框
class CBackkomDlg : public CDialogEx
{
// 构造
public:
	CBackkomDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BACKKOM_DIALOG };

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
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditDes();
	afx_msg void OnEnChangeEditSource();
	CEdit m_EditSource;
	CEdit m_EditDes;
	CString m_source;
	CString m_des;
};
