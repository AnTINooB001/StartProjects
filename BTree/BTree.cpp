#include <iostream>
#define WRONG true
class BTree
{
private:
    class Node
    {
    public:
        int data;
        Node* LeftChild = nullptr;
        Node* RightChild = nullptr;
        Node* Parent = nullptr;
        bool First;
        Node(int data = 0)
        {
            this->data = data;
        }
    };
    Node Element;
    Node* pElement;
    
    
    
public:

    class MyException : public std::exception
    {
    private:
        int data = 0;
    public:
        MyException(int data);
        void What();
    };
    BTree(int data)
    {
        Add(data);
    };

    BTree() {};
    
    void Add(int data, Node* temp);
    void Add(int data);
    void search();
    void PrintBTreeData();
    void PrintBTreeData(Node* temp);
};


int main()
{
    std::setlocale(LC_ALL, "ru");
    BTree tree;
    try
    {
        tree.Add(100);
        tree.Add(50);
        tree.Add(10);
        tree.Add(58);
        tree.Add(52);
        tree.Add(53);
        tree.Add(11);
        tree.Add(150);
        tree.Add(130);
        tree.Add(180);
        tree.Add(175);
        tree.Add(160);
    
        tree.PrintBTreeData();
    }
    catch (BTree::MyException& ex)
    {
         ex.What();
    };
    return 0;
}

BTree::MyException::MyException(int data)
{
    this->data = data;
};

void BTree::MyException::What()
{
    std::cout << "Number " << this->data << " already has in tree";
}

void BTree::Add(int data)
{
    return Add(data, pElement);
};

void BTree::Add(int data, Node* temp)
{
    if (Element.First == false)
    {
        pElement = new Node(data);

        Element.First = true;
    }

    else
    {

        if (data == temp->data)//   Exception
        {
            throw MyException(data);
        }

        if (data < temp->data) //   if <
        {

            if (temp->LeftChild != nullptr)
            {
                temp = temp->LeftChild;
                Add(data, temp);
            }
            else
            {
                temp->LeftChild = new Node(data);
                temp->LeftChild->Parent = temp;
            }
        }
        else           //           if >
        {
            if (temp->RightChild != nullptr)
            {
                temp = temp->RightChild;
                Add(data, temp);
            }
            else
            {
                temp->RightChild = new Node(data);
                temp->RightChild->Parent = temp;
            }
        }
    }
}


void BTree::PrintBTreeData(Node* temp)
{
    if (temp->LeftChild != nullptr) PrintBTreeData(temp->LeftChild);
    Node* current = temp;
    std::cout << current->data<<",";

     if (temp->RightChild != nullptr)
    {
         PrintBTreeData(temp->RightChild);
         if(temp != current)
            std::cout << temp->data << ",";
    }
   
};

void BTree::PrintBTreeData()
{
    return PrintBTreeData(pElement);
};

void BTree::search()
{
    while (true)
    {
        std::cout << "a";
        break;
    }
}




