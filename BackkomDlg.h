
// BackkomDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CBackkomDlg �Ի���
class CBackkomDlg : public CDialogEx
{
// ����
public:
	CBackkomDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BACKKOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
