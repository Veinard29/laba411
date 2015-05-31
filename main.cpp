#include <iostream>
#include <list>


using namespace std;



/** \class Node - ����� �������� � ������� ����
 */
class Node{
    list<Node> nodes; /**< ������ �������� ����� */
    int serialNum; /**< ���������� ���� */
 public:
     /** \brief ����������� ��� ����������
      */

     Node();
     /** \brief ����������� � �������� ����������� ����
      *
      * \param [in] serial - ���������� ��� ����
      *
      */

     Node(int);
     /** \brief ����� ���������� �������� �����
      *
      * \param [in] node - ������ �� ������ ����� ����
      *
      */

     void add(const Node&);
     /** \brief ����� ������ �� ������
      *
      * \param [in] serial - ���������� ���� ��� ������
      * \return ������ �� ����
      *
      */

     Node& search(int);
     /** \brief ����� ��������� ����������� ����
      *
      * \return �������� ����
      *
      */

     int  getSerial();
     /** \brief ����� ������������� ������ � �������� �������
      *
      */

     void printForward();
     /** \brief ����� ������������� ������ � ������ �������
      *
      */

     void printBack();
     /** \brief ����� ������������� ������ � ������������ �������
      *
      */

     void printSymetric();
};
Node * node; /**< ���������� ���������� ��� ��������� �� ������� �������� ������ */
Node::Node(){
   // count = 0;
}
void Node::printForward(){

    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printForward();
    }

}
void Node::printBack(){

    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printBack();
    }
    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
}

void Node::printSymetric(){
    bool flag = true;
    if(nodes.size() == 0){
        if(serialNum != 0){
            cout<<serialNum<<" ";
        }
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printSymetric();
        if(flag){
            if(serialNum != 0){
                cout<<serialNum<<" ";
            }
            flag = false;
        }
    }
}
Node::Node(int serial){
    serialNum = serial;
}
int Node::getSerial() {
    return serialNum;
}

Node& Node::search(int num){
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        if((*it).getSerial() == num){
            node = &(*it);
        } else {
            (*it).search(num);
        }
    }
    return (*node);
}

void Node::add(const Node& node){
    nodes.push_back(node);
}

/** \brief ����� main �������� ����� ���������
 *
 * \return ��� ������
 *
 */

int main()
{
    /** \brief ���������� ������ � ����������
     */

    int serialCounter = 0;
    Node * baseNode = new Node(serialCounter);
    int countOfNodes = 0;
    int nextSerial = 0;
    cin>>countOfNodes;

    for(int i = 0;i < countOfNodes; i ++){
        cin>>nextSerial;
        if(nextSerial ==  0){
            ++serialCounter;
            baseNode->add(*(new Node(serialCounter)));
        } else {
            ++serialCounter;
            baseNode->search(nextSerial).add(*(new Node(serialCounter)));
        }

    }
    baseNode->printForward();
    cout<<"\n";
    baseNode->printBack();
    cout<<"\n";
    baseNode->printSymetric();



    return 0;
}

