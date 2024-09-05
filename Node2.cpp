/*
Este patrón Composite
es útil cuando tienes una estructura de objetos en forma de árbol, como en el caso del archivo XML. 
Cada nodo puede contener otros nodos (por ejemplo, un Group que contiene Category, 
y una Category que contiene varias características).
*/

class Node {
public:
    virtual void add(Node* node) = 0;
    virtual void display() = 0;
};

class Group : public Node {
    std::vector<Node*> children;
public:
    void add(Node* node) override {
       
