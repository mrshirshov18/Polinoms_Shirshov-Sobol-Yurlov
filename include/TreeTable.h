#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename Tkey, typename TValue>
class TreeTable
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    struct TNode {
        TTableRec data;
        TNode* pLeft;
        TNode* pRight;
        TNode() {
            pLeft = nullptr;
            pRight = nullptr;
        }
    };
    TNode* pRoot = nullptr;
    void Print(TNode* p) {
        if (p == nullptr)
            return;
        Print(p->pLeft);
        cout << p->data.key << " = ";
        p->data.value.Print(); cout << endl;
        Print(p->pRight);
    }
    TNode* FindNode(Tkey key, TNode* pNode) {
        if (pNode == nullptr)
            return nullptr;
        if (key < pNode->data.key)
            pNode = FindNode(key, pNode->pLeft);
        if (key > pNode->data.key)
            pNode = FindNode(key, pNode->pRight);
        return pNode;
    }
    bool IsLeaf(TNode* pNode) {
        if (pNode->pLeft == pNode->pRight)
            return 1;
        else 0;
    }
    TNode* FindParent(Tkey key, TNode* pNode, TNode* parent) {
        if (pNode == nullptr)
            return parent;
        if (key == pNode->data.key)
            return parent;
        if (IsLeaf(pNode))
            return pNode;
        if (key < pNode->data.key) {
            parent = pNode;
            pNode = FindParent(key, pNode->pLeft, parent);
        }
        if (key > pNode->data.key)
            parent = pNode;
        pNode = FindParent(key, pNode->pRight, parent);

    }

    vector<string> arr;
    void Give(TNode* p) {
        if (p == nullptr)
            return;
        Give(p->pLeft);
        arr.push_back(p->data.key + " = " + p->data.value.GivePolinom());
        Give(p->Right);
    }
public:
    void Print() {
        Print(pRoot);
    }
    TValue* Find(Tkey key) {

        TNode* pNode = FindNode(key, pRoot);
        if (pNode == nullptr)
            return nullptr;
        return &pNode->data.value;
    }
    void Insert(Tkey key, TValue value) {
        //TNode* Node = Find(key, pRoot);
        if (pRoot == NULL) {
            pRoot = new TNode;
            pRoot->data.key = key;
            pRoot->data.value = value;
            return;
        }
        TNode* Node;
        if (key < pRoot->data.key) {
            Node = pRoot->pLeft;
        }
        else
            Node = pRoot->pRight;
        TNode* pNode = FindParent(key, Node, pRoot);
        if (pNode == nullptr)
            return;
        if (key < pNode->data.key) {
            TNode* temp = new TNode;
            pNode->pLeft = temp;
            pNode->pLeft->data.value = value;
            pNode->pLeft->data.key = key;
        }
        if (key > pNode->data.key) {
            pNode->pRight = new TNode;
            pNode->pRight->data.value = value;
            pNode->pRight->data.key = key;
        }
        return;
    }
    void Delete(Tkey key) {
        TNode* mNode;
        if (key < pRoot->data.key) {
            mNode = pRoot->pLeft;
        }
        else
            mNode = pRoot->pRight;
        TNode* pNode = FindParent(key, mNode, pRoot);// parent of Node
        if (pNode == nullptr)
            return;
        TNode* Node = FindNode(key, pRoot);
        if (Node) {
            int flag;
            if (pNode->data.key > Node->data.key) {
                flag = 1;
            }
            else {
                flag = 2;
            }
            if (IsLeaf(Node)) {
                if (Node->data.key < pNode->data.key)
                    pNode->pLeft = nullptr;
                else
                    pNode->pRight = nullptr;
            }
            if (Node->pLeft == nullptr || Node->pRight == nullptr) {

                if (Node->data.key < pNode->data.key)
                    if (Node->pLeft == nullptr)
                        pNode->pLeft = Node->pRight;
                    else
                        pNode->pLeft = Node->pLeft;
                else
                    if (Node->pLeft == nullptr)
                        pNode->pRight = Node->pRight;
                    else
                        pNode->pRight = Node->pLeft;
            }
            if (Node->pLeft == nullptr && Node->pRight == nullptr) {

                TNode* TempNode = Node->pLeft;
                while (TempNode->pRight != nullptr)
                    TempNode = TempNode->pRight;
                TNode* ParTNode = FindParent(TempNode->data.key, TempNode, pRoot);
                if (IsLeaf(TempNode)) {
                    TempNode->pLeft = Node->pLeft;
                    TempNode->pRight = Node->pRight;
                    ParTNode->pRight = nullptr;
                    if (flag == 1)
                        pNode->pLeft = TempNode;
                    else
                        pNode->pRight = TempNode;
                }
                else {
                    ParTNode->pRight = TempNode->pLeft;
                    TempNode->pLeft = Node->pLeft;
                    TempNode->pRight = Node->pRight;
                    if (flag == 1)
                        pNode->pLeft = TempNode;
                    else
                        pNode->pRight = TempNode;
                }
            }

        }
    }
    vector<string> GiveTable() {
        arr.clear();
        Give(pRoot);
        return arr;
    }


};

