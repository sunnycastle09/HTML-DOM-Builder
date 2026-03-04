#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void tokenizer(std::string file_name);
char before_colon(std::string tk);
std::string after_colon(std::string tk);

class Node {
public:
	virtual std::string tag_name() {
		return "Node";
	}

	std::string class_;
	std::string id;
	std::string attribute_name;
	std::string attribute_value;
	std::string href;
	Node* parent = nullptr;
	std::vector<Node*> children;
	bool exp = false;
	virtual std::string o_text() { return ""; }
};

class HTMLDoctypeElement : public Node {
public:
	std::string tag_name() override { return "doctype"; }
};

class HTMLHtmlElement : public Node {
public:
	std::string tag_name() override { return "html"; }
};

class HTMLBodyElement : public Node {
public:
	std::string tag_name() override { return "body"; }

};

class HTMLMetaElement : public Node {
public:
	std::string tag_name() override { return "meta"; }
	std::string charset;
};

class HTMLHeadElement : public Node {
public:
	std::string tag_name() override { return "head"; }
};

class HTMLTitleElement : public Node {
public:
	std::string tag_name() override { return "title"; }
};

class HTMLHeaderElement : public Node {
public:
	std::string tag_name() override { return "header"; }
};

class HTMLH1Element : public Node {
public:
	std::string tag_name() override { return "h1"; }
};

class HTMLH2Element : public Node {
public:
	std::string tag_name() override { return "h2"; }
};

class HTMLNavElement : public Node {
public:
	std::string tag_name() override { return "nav"; }
};

class HTMLSectionElement : public Node {
public:
	std::string tag_name() override { return "section"; }
};

class HTMLFooterElement : public Node {
public:
	std::string tag_name() override { return "footer"; }
};

class HTMLDivElement : public Node {
public:
	std::string tag_name() override { return "div"; }
};

class HTMLSpanElement : public Node {
public:
	std::string tag_name() override { return "span"; }
};

class HTMLParagraphElement : public Node {
public:
	std::string tag_name() override { return "p"; }
};

class HTMLAnchorElement : public Node {
public:
	std::string tag_name() override { return "a"; }
};

class HTMLImageElement : public Node {
public:
	std::string tag_name() override { return "src"; }
	std::string src;
	int width = 0;
	int height = 0;
};

class HTMLScriptElement : public Node {
public:
	std::string tag_name() override { return "script"; }
	std::string code;
};

class HTMLInputElement : public Node {
public:
	std::string tag_name() override { return "input"; }
	std::string value;
};

class HTMLButtonElement : public Node {
public:
	std::string tag_name() override { return "button"; }
};

class HTMLUListElement : public Node {
public:
	std::string tag_name() override { return "ul"; }
};

class HTMLOListElement : public Node {
public:
	std::string tag_name() override { return "ol"; }
};

class HTMLLIElement : public Node {
public:
	std::string tag_name() override { return "li"; }
};

class HTMLBRElement : public Node {
public:
	std::string tag_name() override { return "br"; }
};

class HTMLCharacterElement : public Node {
public:
	std::string text;
	HTMLCharacterElement(std::string a) {
		text = a;
	}
	std::string tag_name() override { return "character"; }
	std::string o_text() override{
		return text;
	}
};
void print_tree(Node* node, int depth);
std::string character_node_buffer="";
int main() {
	std::string a = "index.html";
	std::string token;
	tokenizer(a);
	std::ifstream file("token.txt");
	std::ofstream outFile("token_excepted_attribute.txt");
	std::vector<char> token_state;
	std::vector<Node*> sooe;
	int indexer = 1;
	while (std::getline(file, token)) {
		if (token[0] != 'A') {
			outFile << token << "\n";
		}
	}
	file.close();
	outFile.close();
	std::ifstream file2("token_excepted_attribute.txt");//ifstream뭔가 이상
	while (std::getline(file2, token)) {
		if ((after_colon(token) == "src") &&(after_colon(token) == "br") && (after_colon(token) == "mata") && (after_colon(token) == "img") && (after_colon(token) == "input")) {
			token_state.push_back('c');
		}
		else {
			token_state.push_back(before_colon(token));//d , s,  s ...	
		}
	}
	file2.close();
	std::ifstream file3("token_excepted_attribute.txt");
	std::getline(file3, token);
	HTMLDoctypeElement origin;
	sooe.push_back(&origin);
	std::string token_value;
	character_node_buffer = "";
	while (std::getline(file3, token)) {
		token_value = after_colon(token);
		if (token_value == "html") { sooe.push_back(new HTMLHtmlElement()); }
		else if (token_value == "body") { sooe.push_back(new HTMLBodyElement()); }
		else if (token_value == "head") { sooe.push_back(new HTMLHeadElement()); }
		else if (token_value == "meta") { sooe.push_back(new HTMLMetaElement()); }
		else if (token_value == "title") { sooe.push_back(new HTMLTitleElement()); }
		else if (token_value == "header") { sooe.push_back(new HTMLHeaderElement()); }
		else if (token_value == "h1") { sooe.push_back(new HTMLH1Element()); }
		else if (token_value == "h2") { sooe.push_back(new HTMLH2Element()); }
		else if (token_value == "nav") { sooe.push_back(new HTMLNavElement()); }
		else if (token_value == "section") { sooe.push_back(new HTMLSectionElement()); }
		else if (token_value == "footer") { sooe.push_back(new HTMLFooterElement()); }
		else if (token_value == "div") { sooe.push_back(new HTMLDivElement()); }
		else if (token_value == "span") { sooe.push_back(new HTMLSpanElement()); }
		else if (token_value == "p") { sooe.push_back(new HTMLParagraphElement()); }
		else if (token_value == "a") { sooe.push_back(new HTMLAnchorElement()); }
		else if (token_value == "src") { sooe.push_back(new HTMLImageElement()); }
		else if (token_value == "input") { sooe.push_back(new HTMLInputElement()); }
		else if (token_value == "ul") { sooe.push_back(new HTMLUListElement()); }
		else if (token_value == "li") { sooe.push_back(new HTMLLIElement()); }
		else if (token_value == "br") { sooe.push_back(new HTMLBRElement()); }
		else if(token_value=="character") { sooe.push_back(new HTMLCharacterElement(character_node_buffer)); character_node_buffer = ""; }
		if (token_state[indexer] == 'e') {
			sooe.pop_back();
			sooe.pop_back();
		}
		else if ((token_state[indexer] == 'c')|| (sooe[sooe.size() - 1]->tag_name() == "br") || (sooe[sooe.size() - 1]->tag_name() == "meta") || (sooe[sooe.size() - 1]->tag_name() == "input") || (sooe[sooe.size() - 1]->tag_name() == "src")) {
			sooe[sooe.size() - 1]->parent = sooe[sooe.size() - 2];
			for (int i = 0; i < sooe.size() - 1; i++) {
				sooe[i]->children.push_back(sooe[sooe.size() - 1]);
			}
			sooe.pop_back();
		}
		else {
			for (int i = 0; i < sooe.size() - 1; i++) {
				sooe[i]->children.push_back(sooe[sooe.size() - 1]);
			}
		}
		indexer++;
	}//while문 끝
	print_tree(&origin, 0);

}

void print_tree(Node* node, int depth) {
	for (int i = 0; i < depth; i++) {
		std::cout << "  ";
	}
	if (node->tag_name() == "character") {
		// 'character' 대신 실제 텍스트 내용을 출력
		std::cout << node->o_text() << "\n";
	}
	else {
		std::cout << node->tag_name() << "\n";
	}
	for (Node* a : node->children) {
		if (!a->exp) { print_tree(a, depth + 1); }
	}
	if ((node->tag_name() != "character") && (node->tag_name() != "br") && (node->tag_name() != "meta") && (node->tag_name() != "input")&& (node->tag_name() != "src")) {
		for (int i = 0; i < depth; i++) {
			std::cout << "  ";
		}
		std::cout << "/" << node->tag_name() << "\n";
	}
	node->exp = true;
}


std::string after_colon(std::string tk) {
	std::string temp;
	if (tk[0] == 'S') {
		for (int i = 9; i < tk.size(); i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'E') {
		for (int i = 7; i < tk.size(); i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'D') {
		for (int i = 8; i < tk.size(); i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'C') {
		for (int i = 10; i < tk.size(); i++) {
			character_node_buffer += tk[i];
		}
		temp = "character";

	}
	return temp;
}
char before_colon(std::string tk) {
	if (tk[0] == 'S') {
		return 's';
	}
	else if (tk[0] == 'E') {
		return 'e';
	}
	else if (tk[0] == 'D') {
		return 'd';
	}
	else if (tk[0] == 'C') {
		return 'c';
	}
}

void tokenizer(std::string file_name) {
	char c;
	bool is_first = true;
	std::string state = "DOCTYPE";
	std::string character_buffer = "";
	std::string tagname_buffer = "";
	std::string attribute_buffer = "";
	std::ifstream inFile(file_name); //html 파일 읽기
	std::ofstream outFile("token.txt");//token 파일 쓰기
	while (inFile.get(c)) {
		if (state == "DOCTYPE") {
			if (c != '<') {
				if (c == '>') {
					outFile << "DOCTYPE:" << character_buffer << "\n";
					character_buffer = "";
					state = "Data";
				}
				else {
					character_buffer += c;
				}
			}
		}
		else if (state == "Data") {
			if (c == '<') {
				state = "Tag Open";
			}
			else {
				state = "Character"; character_buffer += c;
			}
		}
		else if (state == "Tag Open") {
			if (c != '/') {
				if (c == '>') {
					outFile << "StartTag:" << tagname_buffer << "\n";
					tagname_buffer = "";
					state = "Data";
				}
				else if (c == ' ') {
					outFile << "StartTag:" << tagname_buffer << "\n";
					tagname_buffer = "";
					state = "Attribute Name";
				}
				else {
					tagname_buffer += c;
				}
			}
			else {
				state = "Tag Close";
			}
		}
		else if (state == "Tag Close") {
			if (c != '/') {// tag close에서 /문자 담기는건 피하기 위해
				if (c == '>') {
					outFile << "EndTag:" << tagname_buffer << "\n";
					tagname_buffer = "";
					state = "Data";
				}
				else {
					tagname_buffer += c;
				}
			}
		}
		else if (state == "Character") {
			if (c == '<') {
				outFile << "Character:" << character_buffer << "\n";
				character_buffer = "";
				state = "Tag Open";
			}
			else {
				character_buffer += c;
			}
		}
		else if (state == "Attribute Name") {
			if (c == '>') {
				outFile << "Attribute Name:" << attribute_buffer << "\n";
				attribute_buffer = "";
				state = "Data";
			}
			else if (c != '=') {
				attribute_buffer += c;
			}
			else {
				outFile << "Attribute Name:" << attribute_buffer << "\n";
				attribute_buffer = "";
				state = "Attribute Value";
			}
		}
		else if (state == "Attribute Value") {
			if (!is_first) {
				if (c == '\"') {
					outFile << "Attribute Value:" << attribute_buffer << "\n";
					attribute_buffer = "";
					state = "After Attribute Value";
					is_first = true;
				}
				else {
					attribute_buffer += c;
				}
			}
			else {
				is_first = false;
			}
		}
		else if (state == "After Attribute Value") {
			if (c == '>') {
				state = "Data";
			}
			else if (c == ' ') {
				state = "Attribute Name";
			}
		}

	}
}