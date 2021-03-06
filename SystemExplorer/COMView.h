#pragma once

#include "VirtualListView.h"
#include "Interfaces.h"
#include "ViewBase.h"

class CComView :
	public CVirtualListView<CComView>,
	public CViewBase<CComView> {
public:
	CComView(IMainFrame* frame);

	BEGIN_MSG_MAP(CComView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnSelectedTreeItemChanged)
		CHAIN_MSG_MAP(CViewBase<CComView>)
		CHAIN_MSG_MAP(CVirtualListView<CComView>)
	END_MSG_MAP()

	CString GetColumnText(HWND, int row, int col) const;
	int GetRowImage(int row) const;

	void DoSort(const SortInfo*);

private:
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnSelectedTreeItemChanged(int, LPNMHDR hdr, BOOL&);

	void InitTree();
	CTreeItem CreateRootItem(PCWSTR name, WinSys::ComStore store);
	void CreateStoreItems(CTreeItem root);
	void UpdateList(CTreeItem item);
	
	CString GetColumnTextClass(int row, int col) const;
	CString GetColumnTextInterface(int row, int col) const;
	
	void InitListViewClasses();
	void InitListViewInterfaces();

	void DoSortClasses(const SortInfo*);
	void DoSortInterfaces(const SortInfo* si);

	static CString ClsidToString(const GUID& guid);
	static PCWSTR ServerTypeToString(WinSys::ComServerType type);

	enum class NodeType {
		Classes, Interfaces, Typelibs, AppIds,
		COUNT
	};

private:
	std::vector<WinSys::ComClassInfo> m_Classes;
	std::vector<WinSys::ComInterfaceInfo> m_Interfaces;

	std::function<CString(int, int)> m_GetColumnTextFunctions[(int)NodeType::COUNT];
	std::function<void()> m_InitListView[(int)NodeType::COUNT];
	std::function<void(const SortInfo*)> m_Sorter[(int)NodeType::COUNT];

	CTreeItem m_SelectedNode;
	WinSys::ComExplorer m_ComExplorer;
	CTreeViewCtrlEx m_Tree;
	CListViewCtrl m_List;
	CSplitterWindow m_Splitter;
	WinSys::ComExplorer m_Com;
};

