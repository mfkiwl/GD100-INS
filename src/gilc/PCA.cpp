// PCA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "PCA.h"
using namespace Eigen;
using namespace std;
double New_data[pca_N] = { 0 };
static double datasum[3] = { 0 };
static double datasum_new[2] = { 0 };
static double acc_x_win2[5] = { 0 };
static double acc_y_win2[5] = { 0 };
static double acc_z_win2[5] = { 0 };
static double sum_car_yaw = 0;
static double last_car_yaw = 0;
int first_acc = 0;
static int start_num = 0;
static int static_num = 0;
int PCA_Filter::Pca_Process_Angle(double Acc[3], double result[3],  int car_status)
{
	MatrixXf Data_angle(3, pca_N);//��ʼ��������
	MatrixXf Data_mean(3, pca_N);//��ʼ��������
	MatrixXf Cov_angle(pca_N, pca_N);//��ʼЭ�������
	MatrixXf Feature_value(2, pca_N );//����ֵ
	MatrixXf Feature_mat(2, pca_N);//��������
	MatrixXf New_data_mat(2, 3);
	static int  D_num = pca_N;
	static double vel_heading_sum = 0;
	static double pitch_sum = 0;
	static double roll_sum = 0;
	static double last_heading = 0;
	if (!mat_init)
	{
		Data_angle = MatrixXf::Zero(3, pca_N);
		Data_mean = MatrixXf::Zero(3, pca_N);
		Cov_angle = MatrixXf::Zero(pca_N, pca_N);
		Feature_value = MatrixXf::Zero(2, pca_N );
		Feature_mat = MatrixXf::Zero(2, pca_N);
		New_data_mat=MatrixXf::Zero(2, 3);
		pca_init();
		mat_init = true;
	}
	if (acc_x.size() < pca_N)
	{
		acc_x.push_back(Acc[0]);//���ٶȳ�ʼ������
		acc_y.push_back(Acc[1]);
		acc_z.push_back(Acc[2]);
		//printf("************%d*************\n", acc_x.size());
	}
	else
	{
		for (int i = 0;i < pca_N - 1;i++)
		{
			acc_x[i] = acc_x[i + 1];//���ڻ���
			acc_y[i] = acc_y[i + 1];
			acc_z[i] = acc_z[i + 1];
		}
		acc_x[pca_N - 1] = Acc[0];
		acc_y[pca_N - 1] = Acc[1];
		acc_z[pca_N - 1] = Acc[2];
		for (int i = 0;i < pca_N;i++)
		{
			datasum[0] += acc_x[i];
			datasum[1] += acc_y[i];
			datasum[2] += acc_z[i];
			//double car_acc = sqrt(acc_x[i] * acc_x[i] + acc_y[i] * acc_y[i] + acc_z[i] * acc_z[i]) - GN;
			//a_car.push_back(car_acc);//ʵʱ����ǰ��������ٶ�
		}
		//printf("sum=%f,%f,%f\n", datasum[0], datasum[1], datasum[2]);
		Mean_data[0] = datasum[0] / pca_N;//���ֵ(������)
		Mean_data[1] = datasum[1] / pca_N;//���ֵ������ǣ�
		Mean_data[2] = datasum[2] / pca_N;//���ֵ������ǣ�
		//New_data[0] = datasum[0];
		//New_data[1] = datasum[1];
		for (int i = 0;i < pca_N;i++)
		{
			Data_mean(0, i) = Mean_data[0];
			Data_mean(1, i) = Mean_data[1];
			Data_mean(2, i) = Mean_data[2];
		}
		for (int j = 0;j <pca_N;j++)
		{
			Data_angle(0, j) = acc_x[j];//����ֵ
			Data_angle(1, j) = acc_y[j];//����ֵ
			Data_angle(2, j) = acc_z[j];//����ֵ
		}
			//printf("pca->Sum_data=%f,%f\n", datasum[0], datasum[1]);
			Data_angle = Data_angle - Data_mean;//���ݼ�ȥ��ֵ
			//printf("PCA_data\n");
			//cout << Data_mean << endl;
			//cout << Data_angle << endl;
			MatrixXf zeroMeanMat = Data_angle;
			MatrixXf covMat;
			//cout << pca->Mean_data << endl;
			if (Data_angle.rows() == 1)//����Ϊ1
				covMat = (zeroMeanMat.adjoint()*zeroMeanMat) / double(Data_angle.rows());//Э�������
			else
				covMat = (zeroMeanMat.adjoint()*zeroMeanMat) / double(Data_angle.rows() - 1);
			//printf("covMat\n");
			//cout << covMat << endl;
			EigenSolver<Eigen::MatrixXf> es(covMat);
			MatrixXf D = es.pseudoEigenvalueMatrix();//����ֵ����
			MatrixXf V = es.pseudoEigenvectors();//��������
			//cout << D << endl;
			//cout << V << endl;
			for (int i = 0;i < pca_N;i++)
			{
				D_angle.push_back(D(i, i));//��ȡ����ֵ
			}
			double min_D = 1e100;
			static int index_min = 0;
			static int index_s_min = 0;
			static int index_t_min = 0;
			static int index_f_min = 0;
			for (int i = 0;i < pca_N;i++)//������Сֵ��λ��
			{
				if (D_angle[i] <= min_D)
				{
					min_D = D_angle[i];
					index_min = i;
				}
			}
			double min_s_D = 1e100;
			for (int i = 0;i < pca_N;i++)//�����ڶ���Сֵ��λ��
			{
				if (D_angle[i] >min_D&&D_angle[i]<min_s_D)
				{
					min_s_D = D_angle[i];
					index_s_min = i;
				}
			}
			for (int i = 0;i < pca_N;i++)
			{
				Feature_mat(0, i) = V(i, index_min);//����������ȡ
				Feature_mat(1, i) = V(i, index_s_min);
			}
			New_data_mat = Feature_mat*Data_angle.transpose();//�����ع�
			double pitch[2] = { 0 };
			double roll[2] = { 0 };
			double yaw[2] = { 0 };
				for (int i = 0;i < 2;i++)
				{
					pitch[i] = atan2((New_data_mat(i, 0) + Mean_data[0]), -(New_data_mat(i, 2) + Mean_data[2]));
					roll[i] = atan2(-(New_data_mat(i, 1) + Mean_data[1]), -(New_data_mat(i, 2) + Mean_data[2]));
					//yaw[i] = atan2((New_data_mat(i, 0) + Mean_data[0]), New_data_mat(i, 1) + Mean_data[1]);
				}
				double yaw1= 0;
				Car_Angle[0] = (pitch[0] + pitch[1]) / 2;
				Car_Angle[1] = (roll[0] + roll[1]) / 2;
				
				double acc2[3] = { 0 };
				acc2[0] = Acc[0];//��ʵʱ���ٶȽ��е�ƽ
				acc2[1] = Acc[1];
				acc2[2] = Acc[2];
				//acc2[0] = New_data_mat(0, 0) + Mean_data[0];//���ع����ٶȽ��е�ƽ
				//acc2[1] = New_data_mat(0, 1) + Mean_data[1];
				//acc2[2] = New_data_mat(0, 2) + Mean_data[2];
				Comp_InstallErr_Acc(acc2, Car_Angle[1], Car_Angle[0]);//���ٶȸ��������ƽ
				double acc_car1 = sqrt(acc2[0] * acc2[0] + acc2[1] * acc2[1]);
					if (car_status)//����̬�жϣ���̬car_status==1
					{
						if (pca_pitch.size() < 200)//�ɼ�200��ƽ��
						{
							pca_pitch.push_back(Car_Angle[0]);
							pca_roll.push_back(Car_Angle[1]);
						}
						else
						{
							double p_sum = 0;
							double r_sum = 0;
							for (int i = 0;i < 200;i++)
							{
								p_sum += pca_pitch[i];
								r_sum += pca_roll[i];
							}
							result[0] = p_sum/200;//�����Ǹ�ֵ
							result[1] = r_sum/200;//����Ǹ�ֵ
							pca_pitch.clear();
							pca_roll.clear();
						}
						if (start_num % 100 == 0)
						{
						printf("pitch=%f,roll=%f\n", result[0] * R2D, result[1] * R2D);
						}
					}
				double yaw3 = 0;
				if (start_num>50&& !car_status)
				{
					if (start_num > 6000)//һ����δ���ɹ����˳����
					{
						result[0] = 0;
						result[1] = 0;
						result[2] = 0;
						gilc_log("pca_fail!!\r\n");
						return 1;
					}
					if (((fabs(acc2[0]) > 0.01 || fabs(acc2[1]) > 0.01)) && (acc_car1 > 0.01) && (acc_car1 < 1))
					{
						yaw3 = -atan2(acc2[1], acc2[0]);

						if (car_yaw.size() < car_yaw_win)
						{

							if (fabs(fabs(yaw3) >= PI * 16 / 18))//160������
							{
								//if (static_num % 5000 == 0)
								//{
								//	printf("���޽Ƕȣ���\n");
								//}
								car_yaw.push_back(fabs(yaw3));//���ٶȳ�ʼ������
							}
							else
							{
								car_yaw.push_back(yaw3);//���ٶȳ�ʼ������
							}
							//if (static_num % 5000== 0)
							//{
							//	printf("���������У�����\n");
							//}
						}
						else
						{
							for (int i = 0;i <car_yaw_win;i++)
							{
								sum_car_yaw += car_yaw[i];
							}
							//printf("sum=%f\n", sum_car_yaw);
							if (first_acc == 0)//��һ�μ��ٹ���
							{
								result[2] = sum_car_yaw / car_yaw_win;//��λƫ�Ǹ�ֵ
								first_acc = 1;
								return 1;
							}
							sum_car_yaw = 0;
						}
					}
					else
					{
						car_yaw.clear();//�������������������
						return 0;
					}
					if ((fabs(yaw3 - last_car_yaw)>PI / 4) && (fabs(yaw3 - last_car_yaw) < 2 * PI * 5 / 6))
					{
						car_yaw.clear();//�������������������
						return 0;
					}
				}
				start_num++;
				last_car_yaw = yaw3;
				Car_Angle[2] = yaw3;

			//printf("�����ع�\n");
			//cout << Feature_mat << endl;
			//cout << Data_angle.transpose() << endl;
		pitch_sum = 0;
		roll_sum = 0;
		vel_heading_sum = 0;
		Data_angle = MatrixXf::Zero(2, 2);
		D_angle.clear();//�������
		acc_yaw.clear();
		//car_yaw.clear();
		datasum[0] = 0;
		datasum[1] = 0;
		datasum[2] = 0;
	}
	
}

void  PCA_Filter::pca_init(void)
{
	Max_data = 0;
	MAX_index = 0;
	Mean_data[2] = {0};
	Min_data[3] = {0};
	Min_s_data[3] = {0};
	Min_t_data[3] = { 0 };
	Min_f_data[3] = { 0 };
	Min_index = 0;
	Sum_data[2] = {0};
	New_data[2] = { 0 };
	New_angle[3] = { 0 };
	Car_Angle[3] = { 0 };
}

int NUM_acc2 = 0;
int AccFilter(double acc[3], double result[2])
{
	double smooth_ax = 0, smooth_ay = 0, smooth_az = 0, smooth_gz = 0;
	if (NUM_acc2 < WinLen)
	{
		acc_x_win2[NUM_acc2] = acc[0];
		acc_y_win2[NUM_acc2] = acc[1];
		acc_z_win2[NUM_acc2] = acc[2];
	}
	else
	{
		for (int i = 0;i < WinLen;i++)
		{
			acc_x_win2[i] = acc_x_win2[i + 1];
			acc_y_win2[i] = acc_y_win2[i + 1];
			acc_z_win2[i] = acc_z_win2[i + 1];
		}
		acc_x_win2[WinLen - 1] = acc[0];
		acc_y_win2[WinLen - 1] = acc[1];
		acc_z_win2[WinLen - 1] = acc[2];
		smooth_ax = dataFilter(acc_x_win2, WinLen);
		smooth_ay = dataFilter(acc_y_win2, WinLen);
		smooth_az = dataFilter(acc_z_win2, WinLen);
		result[0] = atan2(smooth_ax, smooth_az)*R2D;
		result[1] = atan2(smooth_ay, smooth_az)*R2D;
	}
	NUM_acc2++;
	return 1;
}

double dataFilter(double acc_win[], int count)
{
	double MAX = 0, MIN = 0;
	double sum = 0;
	double sum1 = 0;
	MAX = acc_win[0];
	MIN = acc_win[0];
	sum = acc_win[0];
	sum1 = acc_win[0];
	for (int i = 1;i<count; i++)
	{
		if (acc_win[i] > MAX)
		{
			MAX = acc_win[i];
		}
		if (acc_win[i] < MIN)
		{
			MIN = acc_win[i];
		}
		sum += acc_win[i];
		sum1 += acc_win[i];
	}
	double equal_data = (sum - MAX - MIN) / (count - 2);
	sum1 = sum1 / count;
	//printf("data:%f,%f,%f,%f,%f,MAX=%f,MIN=%f,%f,%f\n",acc_win[0], acc_win[1], acc_win[2], acc_win[3], acc_win[4],MAX, MIN,equal_data,sum1);
	return equal_data;
}

int acc_yaw_correct(double angle,double last_angle, double result)
{
	if (angle < 0)
	{
		angle += 2 * PI;
	}
	if (fabs(angle - last_angle)>PI)
	{
		if (angle > PI)
		{
			angle -= 2 * PI;
		}
	}
	result = angle;
	return 1;
}



int InitAngle_Err(double acc[3], double gyro[3], double pos[3],double Init_angle[3])
{
	//ѡȡENU����ϵ
	double gn[3] = { 0 };
	gn[2] = pca_GN;
	MatrixXf wn(3, 1);
	MatrixXf gwB(3, 3);//��ʼ��������
	MatrixXf gwN_inv(3, 3);//��ʼ��������
	MatrixXf gwN(3, 3);//��ʼ��������
	MatrixXf Cb2n(3, 3);//��ʼЭ�������
	MatrixXf gnx(3, 3);//��ʼЭ�������
	MatrixXf gbx(3, 3);//��ʼЭ�������
	wn = MatrixXf::Zero(3, 1);
	gwB = MatrixXf::Zero(3, 3);
	gwN = MatrixXf::Zero(3, 3);
	Cb2n= MatrixXf::Zero(3, 3);
	gnx = MatrixXf::Zero(3, 3);
	gbx = MatrixXf::Zero(3, 3);
	gwN_inv = MatrixXf::Zero(3, 3);

	wn(1,0) = pca_wie*cos(pos[0]);
	wn(2,0)= pca_wie*sin(pos[0]);
	gnx(0, 1) = pca_GN;
	gnx(1, 0) = -pca_GN;
	gbx(0, 1) = -acc[2];
	gbx(0, 2) = acc[1];
	gbx(1, 0) = acc[2];
	gbx(1, 2) = -acc[0];
	gbx(2, 0) = -acc[1];
	gbx(2, 1) = acc[0];
	MatrixXf gnxw = gnx*wn;
	MatrixXf gbxw = gbx*wn;
	for (int i = 0;i < 3;i++)
	{
		gwB(0, i) = acc[i];//����ϵ���ٶ� m/s2
		gwB(1, i) = gyro[i];//����ϵ���ٶ� rad/s
		gwB(2, i) = gbxw(i, 0);
		gwN(0, i) = gn[i];
		gwN(1, i) = wn(i,0);
		gwN(2, i) = gnxw(i, 0);
	}
	gwB.row(0).normalize();//��λ��
	gwB.row(1).normalize();
	gwN_inv = gwN.inverse();//����
	Cb2n = gwN_inv*gwB;
	//NED
	//Init_angle[1] = atan2(Cb2n(2, 1), Cb2n(2, 2));//roll
	//Init_angle[2] = atan2(Cb2n(1, 0), Cb2n(0, 0));//yaw
	//Init_angle[0] = atan2(-Cb2n(2, 0), sqrt(Cb2n(2, 1)*Cb2n(2, 1)+ Cb2n(2, 2)*Cb2n(2, 2)));//pitch
	//ENU
	Init_angle[1] = atan2(-Cb2n(2, 0), Cb2n(2, 2));//roll
	Init_angle[2] = atan2(Cb2n(0, 1), Cb2n(1, 1));//yaw
	Init_angle[0] = atan2(Cb2n(2, 1), sqrt(Cb2n(2, 0)*Cb2n(2, 0)+ Cb2n(2, 2)*Cb2n(2, 2)));//pitch
	return 1;
}

int InitAngle_Err1(double acc[3], double gyro[3], double pos[3], double Init_angle[3])
{
	//ѡȡENU����ϵ
	MatrixXf A(3, 3);//��ʼ��������
	MatrixXf B(3, 3);//��ʼ��������
	MatrixXf Cb2n(3, 3);//��ʼЭ�������

	A = MatrixXf::Zero(3, 3);
	B = MatrixXf::Zero(3, 3);
	Cb2n = MatrixXf::Zero(3, 3);
	A(0, 2) = 1 / (-pca_GN*pca_wie*cos(pos[0]));
	A(1, 0) = sin(pos[0]) / (-pca_GN*cos(pos[0]));
	A(1, 1) = 1 / (pca_wie*cos(pos[0]));
	A(2, 0) = 1 / pca_GN;
	double mb[3] = { 0 };
	mb[0] = acc[1] * gyro[2] - acc[2] * gyro[1];
	mb[1] = acc[2] * gyro[0] - acc[0] * gyro[2];
	mb[2] = acc[0] * gyro[1] - acc[1] * gyro[0];
	B(0, 0) = acc[0];	B(0, 1) = acc[1];	B(0, 2) = acc[2];
	B(1, 0) = gyro[0];	B(1, 1) = gyro[1];	B(1, 2) = gyro[2];
	B(2, 0) = mb[0];	B(2, 1) =mb[1];	B(2, 2) = mb[2];
	Cb2n = A*B;


	//Cb2n.col(0).normalize();
	//double temp;
	//for (std::size_t k = 0; k != Cb2n.cols() - 1; ++k)
	//{
	//	for (std::size_t j = 0; j != k + 1; ++j)
	//	{
	//		temp = Cb2n.col(j).transpose() * Cb2n.col(k + 1);
	//		Cb2n.col(k + 1) -= Cb2n.col(j) * temp;
	//	}
	//	Cb2n.col(k + 1).normalize();
	//}

	//NED
	//Init_angle[1] = atan2(Cb2n(2, 1), Cb2n(2, 2));//roll
	//Init_angle[2] = atan2(Cb2n(1, 0), Cb2n(0, 0));//yaw
	//Init_angle[0] = atan2(-Cb2n(2, 0), sqrt(Cb2n(2, 1)*Cb2n(2, 1)+ Cb2n(2, 2)*Cb2n(2, 2)));//pitch
	//ENU
	Init_angle[1] = atan2(-Cb2n(2, 0), Cb2n(2, 2));//roll
	Init_angle[2] = atan2(-Cb2n(0, 1), Cb2n(1, 1));//yaw
	Init_angle[0] = atan2(Cb2n(2, 1), sqrt(Cb2n(2, 0)*Cb2n(2, 0) + Cb2n(2, 2)*Cb2n(2, 2)));//pitch
	return 1;
}

void Comp_InstallErr_Acc(double acc[3], double installroll, double installpitch)
{
	double cphi = cos(installroll); double sphi = sin(installroll);
	double cthe = cos(installpitch); double sthe = sin(installpitch);
	//calculate levering matrix
	double C3[9] = { 0 }, C2[9] = { 0 };
	C3[0 * 3 + 0] = 1.0;
	C3[1 * 3 + 1] = cphi;  C3[1 * 3 + 2] = sphi;
	C3[2 * 3 + 1] = -sphi; C3[2 * 3 + 2] = cphi;
	C2[0 * 3 + 0] = cthe;                        C2[0 * 3 + 2] = -sthe;
	C2[1 * 3 + 1] = 1.0;
	C2[2 * 3 + 0] = sthe;                        C2[2 * 3 + 2] = cthe;

	double Clevel[3 * 3] = { 0.0 }, Ctemp[3 * 3] = { 0.0 };
	Mmulnm(C3, C2, 3, 3, 3, Ctemp);
	Mtn(Ctemp, 3, 3, Clevel);

	double acc_comp[3] = { 0.0 };
	Mmulnm(Clevel, acc, 3, 3, 1, acc_comp);

	Mequalm(acc_comp, 3, 1, acc);
}

vector<double> pca_acc_winx;
vector<double> pca_acc_winy;
vector<double> pca_acc_winz;
int acc_mean(double acc[3], double result[3])
{

	if (pca_acc_winx.size() <acc_WinLen)
	{
		pca_acc_winx.push_back(acc[0]);
		pca_acc_winy.push_back(acc[1]);
		pca_acc_winz.push_back(acc[2]);
		return 0;
	}
	else
	{
		for (int i = 0;i < acc_WinLen-1;i++)
		{
			pca_acc_winx[i] = pca_acc_winx[i + 1];
			pca_acc_winy[i] = pca_acc_winy[i + 1];
			pca_acc_winz[i] = pca_acc_winz[i + 1];
		}
		pca_acc_winx[acc_WinLen - 1] = acc[0];
		pca_acc_winy[acc_WinLen - 1] = acc[1];
		pca_acc_winz[acc_WinLen - 1] = acc[2];
		double sum_accx = 0;
		double sum_accy = 0;
		double sum_accz = 0;
		for (int i = 0;i < acc_WinLen;i++)
		{
			sum_accx += pca_acc_winx[i];
			sum_accy += pca_acc_winy[i];
			sum_accz += pca_acc_winz[i];
		}
		result[0] = sum_accx/ acc_WinLen;
		result[1] = sum_accy / acc_WinLen;
		result[2] = sum_accz / acc_WinLen;
		//pca_acc_winx.clear();
		//pca_acc_winy.clear();
		//pca_acc_winz.clear();
		return 1;
	}
}