/*
Este patrón Factory Method
permite crear objetos NODE sin especificar la clase exacta del objeto que será creado. 
En este caso, podrías usar el Factory Method para instanciar diferentes tipos de nodos 
a partir de las etiquetas XML (Group, Category, IntSwissKnife, StringReg, etc.).
*/

class Node {
public:
    virtual void parseXML(const std::string& xmlContent) = 0;
};

class IntSwissKnife : public Node {
public:
    void parseXML(const std::string& xmlContent) override {
        // Lógica para parsear IntSwissKnife
    }
};

class StringReg : public Node {
public:
    void parseXML(const std::string& xmlContent) override {
        // Lógica para parsear StringReg
    }
};

class NodeFactory {
public:
    static Node* createNode(const std::string& nodeType) {
        if (nodeType == "IntSwissKnife") {
            return new IntSwissKnife();
        } else if (nodeType == "StringReg") {
            return new StringReg();
        }
        return nullptr;
    }
};