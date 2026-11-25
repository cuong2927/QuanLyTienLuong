#include <iostream> 
#include <string>  
using namespace std; 

class NhanVien { 
    private: 
        string HoTen; 
        string maNV; 
        int namSinh; 
        int ngayVL;  
        int soNgayCong; 
        double luongCB; 
    public: 
        //Viet o day222222

}; 

class NhanVienVanPhong : virtual public NhanVien { 
    protected: 
        string phongBan; 
        double heSoCV; 
        double gioLamThem; 
    public: 
        


}; 

class NhanVienKyThuat : virtual public NhanVien { 
    protected: 
        string chuyenNganh;
        int soSP; 
        int bacKN; 
    public: 
        
};

class KySuQuanLy : public NhanVienVanPhong , public NhanVienKyThuat { 
    public:  

}; 

//Day la phan cau 5 



//Cau 6 
class PhongNhanSu { 
    private: 
        NhanVienVanPhong *ds;
    public: 


}; 

template <class T>
class DanhSach {
    private:  
        T *a;
        int soLuong; //so luong phan tu hien co 
        int sucChua; //suc chua toi da cua danh sach

        void resize() { 
            T *moi = new T[sucChua*2]; 
            for(int i=0;i<soLuong;i++) moi[i] = a[i]; 
            delete []a; 
            a=moi; 
            sucChua*=2; 
        }
        
    public: 
    

}; 


//cau 8 
void menuNhanSu() { 
    PhongNhanSu a;

}

void menuDS() { 
    DanhSach<NhanVien*> ds;

} 

int main() { 
    cout<<"Hello world"<<endl;

    return 0;
}
