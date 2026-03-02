#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void tokenizer(std::string file_name);
char before_colon(std::string tk);
std::string after_colon(std::string tk);
//<DOCTYPE>
class HTMLDoctypeElement :public Node {
public:
	std::string tag_name = "doctype";
};
//<html>
class HTMLHtmlElement : public Node {
public:
	std::string tag_name = "html";
};
//<body>
class HTMLBodyElement : public Node {
public:
	std::string tag_name = "body";
};
//<meta>
class HTMLMetaElement : public Node {
public:
	std::string tag_name = "meta";
	std::string charset;
};
//<head>
class HTMLHeadElement : public Node {
public:
	std::string tag_name = "head";
};
//<title>
class HTMLTitleElement : public Node {
public:
	std::string tag_name = "title";
};
//<header>
class HTMLHeaderElement : public Node {
public:
	std::string tag_name = "header";
};
//<h1>
class HTMLH1Element : public Node {
public:
	std::string tag_name = "h1";
};
//<h2>
class HTMLH2Element : public Node {
public:
	std::string tag_name = "h2";
};
//<nav>
class HTMLNavElement : public Node {
public:
	std::string tag_name = "nav";
};
//<section>
class HTMLSectionElement :public Node {
public:
	std::string tag_name = "section";
};
//<footer>
class HTMLFooter :public Node {
public:
	std::string tag_name = "footer";
};
// <div>
class HTMLDivElement : public Node {
public:
	std::string tag_name = "div";
};

// <span>
class HTMLSpanElement : public Node {
public:
	std::string tag_name = "span";
};

// <p>
class HTMLParagraphElement : public Node {
public:
	std::string tag_name = "p";
};

// <h1>
class HTMLHeadingElement : public Node {
public:
	std::string tag_name = "h1";
};
// <a>
class HTMLAnchorElement : public Node {
public:
	std::string tag_name = "a";
};

// <img>
class HTMLImageElement : public Node {
public:
	std::string tag_name = "img";
	std::string src;
	int width;
	int height;
};

// <script>
class HTMLScriptElement : public Node {
public:
	std::string tag_name = "script";
	std::string code;
};

// <input>
class HTMLInputElement : public Node {
public:
	std::string tag_name = "input";
	std::string value;
};

// <button>
class HTMLButtonElement : public Node {
public:
	std::string tag_name = "button";
};
// <ul>
class HTMLUListElement : public Node {
public:
	std::string tag_name = "ul";
};
//<ol>
class HTMLOListElement : public Node {
public:
	std::string tag_name = "ol";
};

// <li>
class HTMLLIElement : public Node {
public:
	std::string tag_name = "li";
};

// <br>
class HTMLBRElement : public Node {
public:
	std::string tag_name = "br";
};
//character
class HTMLCharacterElement : public Node {
	std::string tag_name = "character";
};
class Node {
public:
	std::string class_;
	std::string id;
	std::string attribute_name;
	std::string attribute_value;
	std::string href;
	Node* parent;
	std::vector<Node*> children;
};
int main() {
	std::string a = "index.html";
	std::string token;
	tokenizer(a);
	std::ifstream file("token.txt");
	std::ofstream outFile("token_excepted_attribute.txt");
	std::vector<char> token_state;
	std::vector<Node*> sooe;
	int i = 1;
	while (std::getline(file, token)) {
		if (token[0] != 'A') {
			outFile << token << "\n";
		}
	}
	std::ifstream file2("token_excepted_attribute.txt");
	while (std::getline(file2, token)) {
		token_state.push_back(before_colon(token));//d , s,  s ...	
	}
	std::ifstream file3("token_excepted_attribute.txt");
	sooe.push_back(new HTMLDoctypeElement());
	while (std::getline(file3, token)) {
		if (before_colon(token) != 'e') {
			if (after_colon(token) == "html") { sooe.push_back(new HTMLHtmlElement()); }
			else if (after_colon(token) == "body") { sooe.push_back(new HTMLBodyElement()); }
			else if (after_colon(token) == "head") { sooe.push_back(new HTMLHeadElement()); }
			else if (after_colon(token) == "meta") { sooe.push_back(new HTMLMetaElement()); }
			else if (after_colon(token) == "title") { sooe.push_back(new HTMLTitleElement()); }
			else if (after_colon(token) == "header") { sooe.push_back(new HTMLHeaderElement()); }
			else if (after_colon(token) == "h1") { sooe.push_back(new HTMLH1Element()); }
			else if (after_colon(token) == "h2") { sooe.push_back(new HTMLH2Element()); }
			else if (after_colon(token) == "nav") { sooe.push_back(new HTMLNavElement()); }
			else if (after_colon(token) == "section") { sooe.push_back(new HTMLSectionElement()); }
			else if (after_colon(token) == "footer") { sooe.push_back(new HTMLFooter()); }
			else if (after_colon(token) == "div") { sooe.push_back(new HTMLDivElement()); }
			else if (after_colon(token) == "span") { sooe.push_back(new HTMLSpanElement()); }
			else if (after_colon(token) == "p") { sooe.push_back(new HTMLParagraphElement()); }
			else if (after_colon(token) == "a") { sooe.push_back(new HTMLAnchorElement()); }
			else if (after_colon(token) == "img") { sooe.push_back(new HTMLImageElement()); }
			else if (after_colon(token) == "input") { sooe.push_back(new HTMLInputElement()); }
			else if (after_colon(token) == "ul") { sooe.push_back(new HTMLUListElement()); }
			else if (after_colon(token) == "li") { sooe.push_back(new HTMLLIElement()); }
			else if (after_colon(token) == "br") { sooe.push_back(new HTMLBRElement()); }
		}
		//sooe[sooe.size()-1]<<최상단 인스턴스
		while (1) {//token_state에 +1이 있는 이유는 맨 앞 d를 피하기 위함 
			if ((token_state[i + 1] != sooe[sooe.size() - 1 - i]) && ()) {//해당 인스턴스의 token_state값이 e나 c가 아니면 부모로

			}
		}
	}//while문 끝
}
std::string after_colon(std::string tk)	{
	std::string temp;
	if (tk[0] == 'S') {
		for (int i = 9; i < tk.size()+1; i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'E') {
		for (int i = 7; i < tk.size() + 1; i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'D') {
		for (int i = 8; i < tk.size() + 1; i++) {
			temp += tk[i];
		}
	}
	else if (tk[0] == 'C') {
		for (int i = 10; i < tk.size() + 1; i++) {
			temp += tk[i];
		}
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
	else if (tk[0] == 'C')	{
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
				state = "Tag Close";
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