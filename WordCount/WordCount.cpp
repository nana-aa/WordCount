#include <fstream>
#include <map>
#include <string>
using namespace std;

bool isdigit(char ch)
{
	return (ch >= ' ' && ch <= '9');
}

int main(void)
{
	map<string, int> words;  //תint����
	ifstream fin("input.txt");//Ҫͳ�Ƶ��ļ�
	ofstream fout("output.txt");//��������output��

	string str;
	int wordCount = 0;
	string d;
	int charCount = 0;


	if (!fin || !fout)
	{

		exit(1);
	}
	while (fin.good())
	{
		fin >> str;
		words[str]++;
	}
	fin.close();
	fin.open("input.txt");
	while (getline(fin, d)) //����Ϊ��λ�����ļ�
		charCount += d.size(); //�ۼ��ַ���
	fin.close();

	for (map<string, int>::iterator mit = words.begin(); mit != words.end(); ++mit)
	{
		if (!isdigit((mit->first)[0]))
		{
			fout << "<" << mit->first << ">" << ": " << mit->second << endl;
			++wordCount;
		}
	}
	fout << "wordTotal: " << wordCount << endl;  // �ļ�������ʸ���
	fout << "charTotal: " << charCount << endl;   //�ļ�����ַ�����
	fout.close();
	printf("��������%d\n", wordCount);
	printf("�ַ�����%d\n", charCount);
	return 0;
}