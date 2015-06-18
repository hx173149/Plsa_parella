#define MAX_DOC_NUM_ 50000 
#define MAX_WORD_NUM_ 100000
#define MAX_TOPIC_NUM_ 1000 
#define THREAD_NUM 4

#include <map>

using namespace std;

class PLSAOBJParella
{
  private:
    int doc_num;
    int topic_num;
    int word_num;

    float** pt_d;
    float** pw_t;

    double** in_train_data;
    double m_likehood;

    map<int,float*>  pt_wd;

    void EStep(int start_doc,int end_doc);
    void MStep(int start_topic,int end_topic);
    void LogLikehood(int start_doc,int end_doc);
  
  public:
    PLSAOBJParella();
    ~PLSAOBJParella();
    int TrainModel(double** train_data,int d_num,int w_num,int t_num,double eps,int max_iter);
    int Inference(double* src,double* dst,int& len,int iter_max);
    int SaveModel(const string& filepath);
    int LoadModel(const string& filepath);
    int ContinueTrain(double** train_data,int d_num,int w_num,int t_num,int max_iter);
  //protected:
  public:
    int GetSize(int& d_num,int& t_num,int& w_num);
    float** GetPT_D();
    float** GetPW_T() {return pw_t;};
};
