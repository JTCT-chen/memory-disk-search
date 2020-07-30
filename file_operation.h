#pragma once

#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <assert.h>

#include "common.h"


class File
{
public:
    
    File(std::string file_name);
    ~File();

    /*��ȡһ�����ݣ�timeΪ������ڣ�stock_idΪ��Ʊ��Դ��룻����ֵ��1->�������ݡ�0->û�ж�Ӧ����*/
    int file_read_data(Kline &data, const int time, const int stock_id);

    /*��Χ��ȡ���ݣ�timeΪ������ڣ�stock_idΪ��Ʊ��Դ��룻����ֵ�����������ݸ���*/
    int file_read_data(std::vector<Kline> &data, const int time_start, const int time_end, const int stock_id);

    /*����һ�����ݣ�timeΪ������ڣ�stock_idΪ��Ʊ��Դ��룻����ֵ��0->����ͬ���ݲ����˸��ǡ�1->����ɹ�*/
    int file_insert_data(Kline &data, const int time, const int stock_id);

    /*ɾ��һ�����ݣ�timeΪ������ڣ�stock_idΪ��Ʊ��Դ��룻����ֵ��0->û�ж�Ӧ�����ݡ�1->ɾ���ɹ�*/
    int file_delete_data(const int time, const int stock_id);

    /*�����ļ����ڴ棩��С����λΪ�ֽ�*/
    int get_file_size();


private:

    int block_num;//�����ݿ�����
    int time_max;//�Ѵ�������time���ֵ

    std::vector<int> index;//������
    std::vector<int> stock_num;//��Ʊ��Ŀ��
    std::vector< std::vector<Kline> > day_block;//���ݻ�����

    std::string filename;

    std::ifstream open_file;
    std::ofstream write_file;


};

