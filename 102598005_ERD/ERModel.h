#ifndef _ERMODEL_H_
#define _ERMODEL_H_

#include <vector>
#include "ERComponent.h"
#include "ComponentFactory.h"
#include <QPointF>
#include "gtest/gtest_prod.h"
#include "Subject.h"

using namespace std;

class ERModel : public Subject
{
	friend class ERModelTest;
	FRIEND_TEST(ERModelTest, addComponent);
	FRIEND_TEST(ERModelTest, insertComponent);
	FRIEND_TEST(ERModelTest, findIndex);
	FRIEND_TEST(ERModelTest, deleteLastComponent);
	FRIEND_TEST(ERModelTest, deleteConnection);
	FRIEND_TEST(ERModelTest, deleteComponent);
	FRIEND_TEST(ERModelTest, revertComponent);
	FRIEND_TEST(ERModelTest, insertConnection);
	FRIEND_TEST(ERModelTest, addConnection);
	FRIEND_TEST(ERModelTest, isIDExsit);
	FRIEND_TEST(ERModelTest, getNodeID);
	FRIEND_TEST(ERModelTest, getNodeType);
	FRIEND_TEST(ERModelTest, setPrimaryKey);
	FRIEND_TEST(ERModelTest, getTable);
	FRIEND_TEST(ERModelTest, getOneToOne);
	FRIEND_TEST(ERModelTest, loadComponent);
	FRIEND_TEST(ERModelTest, loadConnection);
	FRIEND_TEST(ERModelTest, loadPrimaryKey);
	FRIEND_TEST(ERModelTest, copy);
	friend class PresentationModelTest;
	FRIEND_TEST(PresentationModelTest, deleteComponentCommand);
	FRIEND_TEST(PresentationModelTest, setPrimaryKey);;
	friend class IntegrationTest;
	FRIEND_TEST(IntegrationTest, testRedoConnectComponent);
	FRIEND_TEST(IntegrationTest, testCommonUsage);
	friend class SetPrimaryKeyCommandTest;
	friend class PasteCommandTest;
	friend class MoveCommandTest;
	friend class EditTextCommandTest;
	friend class DeleteMultipleCommandTest;

public:
	ERModel();
	~ERModel();
	void initialize();
	void clearComponent();
	void addComponent(pair<Type, string> type, string text, QPointF position);
	void insertComponent(int index, ERComponent* component);
	void deleteLastComponent();
	void deleteComponent(int id);
	void deleteConnection(int id);
	vector<ERComponent*> getDeleteList(int id);
	void revertComponent(vector<pair<int, ERComponent*>> deleteList);
	void revertConnector();
	int findIndex(int id);
	void insertConnection(int id, int firstID, int secondID);
	void addConnection(int firstID, int secondID, string cardinality);
	bool isCreationFail();
	bool isType(int id, Type type);
	int getNodeID();
	pair<Type, string> getNodeType(int id);
	string getNodeText(int id);
	ERComponent* getComponent(int id);
	vector<ERComponent*> getComponentList();
	int getComponentSize();
	string getComponentLine(Type type);
	bool isIDExsit(int id);
	string getConnectionLine();
	bool hasConnection(int firstNodeID, int secondNodeID);
	string getAttributeLine(int id);
	bool isAttribute(int entityID, int attributeID);
	bool hasEntity();
	bool hasAttribute(int entityID);
	void setPrimaryKey(vector<int> primaryKey);
	vector<int> getPrimaryKey(int entityID);
	string getPrimaryKeyString(int entityID);
	string getTable();
	vector<pair<int, int>> getOneToOne();
	bool checkOneToOne(pair<int, int> relationPair);
	string getPrimaryKeyText(int entityID);
	bool loadFile(string filePath);
	vector<vector<string>> getFileContent(ifstream &file);
	void loadComponent(vector<string> content);
	void loadConnection(vector<string> content);
	void loadPrimaryKey(vector<string> content);
	string saveFile(ComponentVisitor* visitor);
	void composePosition();
	vector<QPointF> getFilePosition(ifstream &file);
	void loadPosition(vector<QPointF> positionList);
	void setNodePosition(int id, QPointF position);
	bool canSetPrimaryKey(int id);
	void setNodeSelected(int id, bool isSelected);
	vector<int> getSelectedID();
	bool isDeleteEnabled();
	void clearSelected();
	void setNodeText(int index, string text);
	void setNodePrimaryKey(int id, bool isPrimaryKey);
	void deleteMultiple(vector<int> deleteList);
	void copy();
	void paste();
	void unPaste();
	void pasteConnection(vector<pair<int, int>> idTable);
	pair<int, int> getPastedID(vector<pair<int, int>> idTable, pair<int, int> idPair);
	string getGUITable();
	string getGUIPrimaryKey(int id);
	string getGUIForeignKey(int id);
	int getTableLine(int id, vector<pair<int, string>> tableLine);
	bool canPaste();

private:
	vector<ERComponent*> _components;
	ERComponent* _currentComponent;
	int _componentID;	
	bool _creationFail;
	vector<pair<int, ERComponent*>> _buffer;
	vector<ERComponent*> _clipboard;
	int _copyCount;
};

#endif