#include <iostream>
#include <list>


using namespace std;



/** \class Node - класс описани€ и методов пол€
 */
class Node{
    list<Node> nodes; /**< список дочерних полей */
    int serialNum; /**< содержимое пол€ */
 public:
     /** \brief  онструктор без параметров
      */

     Node();
     /** \brief  онструктор с заданием содержимого пол€
      *
      * \param [in] serial - содержимое дл€ ноды
      *
      */

     Node(int);
     /** \brief ћетод добавлени€ дочерних полей
      *
      * \param [in] node - ссылка на объект новой ноды
      *
      */

     void add(const Node&);
     /** \brief ћетод поиска по дереву
      *
      * \param [in] serial - содержимое ноды дл€ поиска
      * \return ссылку на ноду
      *
      */

     Node& search(int);
     /** \brief ћетод получени€ содержимого ноды
      *
      * \return значение ноды
      *
      */

     int  getSerial();
     /** \brief ћетод распечатывает список в обратном пор€дке
      *
      */

     void printForward();
     /** \brief ћетод распечатывает список в пр€мом пор€дке
      *
      */

     void printBack();
     /** \brief ћетод распечатывает список в симметричном пор€дке
      *
      */

     void printSymetric();
};
Node * node; /**< глобальна€ переменна€ дл€ указател€ на искомый элементы списка */
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

/** \brief ћетод main основной метод программы
 *
 * \return код ошибки
 *
 */

int main()
{
    /** \brief «аполнение списка и распечатка
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

