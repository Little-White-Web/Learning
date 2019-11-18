class Matrix{
public:
    Matrix();
    void display();
    Matrix operator+(Matrix a);
private:
    float m[2][3];		//矩阵（二维数组）
    int h;		        //行数
    int l;			//列数
};
