#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;

int main() {
    XMLDocument doc;
	// Verifica que el fichero esté en la ruta del ejecutable. build/Release...
    XMLError result = doc.LoadFile("ejemplo.xml");

    std::cout << "Aplicacion iniciada...  " << std::endl;
    if (result != XML_SUCCESS) {
        std::cerr << "Error loading file: " << result << std::endl;
        return -1;
    }

    XMLNode* root = doc.FirstChild();
    if (root == nullptr) {
        std::cerr << "Error: No root element." << std::endl;
        return -1;
    } else {
        std::cout << "Root element found: " << root->Value() << std::endl;
    }

    // Obtener el elemento <title>
    XMLElement* titleElement = root->FirstChildElement("titulo");
    if (titleElement != nullptr) {
        const char* titleText = titleElement->GetText();
        if (titleText != nullptr) {
            std::cout << "Title: " << titleText << std::endl;
        } else {
            std::cout << "Title element has no text." << std::endl;
        }
    } else {
        std::cout << "Title element not found." << std::endl;
    }

    XMLElement* authorElement = root->FirstChildElement("categoria");
    if (authorElement != nullptr) {
        std::cout << "Author: " << authorElement->GetText() << std::endl;
    }

    XMLElement* contentElement = root->FirstChildElement("content");
    if (contentElement != nullptr) {
        XMLElement* sectionElement = contentElement->FirstChildElement("section");
        XMLElement* valorElement = contentElement->FirstChildElement("valor");
        while (sectionElement != nullptr && valorElement != nullptr) {
            std::cout << "Section: " << sectionElement->GetText() << " con valor " << valorElement->GetText() << std::endl;
            sectionElement = sectionElement->NextSiblingElement("section");
            valorElement   = valorElement->NextSiblingElement("valor");
        }
    }

    return 0;
}