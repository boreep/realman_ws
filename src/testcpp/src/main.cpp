// #include <stdio.h>
// #include "rm_service.h"
// // Windows-specific headers and definitions
// #ifdef _WIN32
// #define SLEEP_MS(ms) Sleep(ms)
// #define SLEEP_S(s) Sleep((s) * 1000)
// #define usleep(us) Sleep((us) / 1000)  // No usleep, use Sleep instead
// // Linux-specific headers and definitions
// #else
// #include <unistd.h>
// #include <sys/time.h>
// #define SLEEP_MS(ms) usleep((ms) * 1000)
// #define SLEEP_S(s) sleep(s)

// #endif

// void custom_api_log(const char* message, va_list args) {
//     if (!message) {
//         fprintf(stderr, "Error: message is a null pointer\n");
//         return;
//     }

//     char buffer[1024];
//     vsnprintf(buffer, sizeof(buffer), message, args);
//     printf(" %s\n",  buffer);
// }


// int main(int argc, char *argv[]) {
//     RM_Service robotic_arm;
//     int result = -1;

//     robotic_arm.rm_set_log_call_back(custom_api_log, 3);
//     result = robotic_arm.rm_init(RM_TRIPLE_MODE_E);
//     if (result != 0) {
//         printf("Initialization failed with error code: %d.\n", result);
//         return -1;
//     }

//     char *api_version = robotic_arm.rm_api_version();
//     printf("API Version: %s.\n", api_version);

//     const char *robot_ip_address = "192.168.1.18";
//     int robot_port = 8080;
//     rm_robot_handle *robot_handle = robotic_arm.rm_create_robot_arm(robot_ip_address, robot_port);
//     if (robot_handle == NULL) {
//         printf("Failed to create robot robot_handle.\n");
//         return -1;
//     } else {
//         printf("Robot robot_handle created successfully: %d\n", robot_handle->id);
//     }
//     rm_arm_software_version_t software_info;
//     result = robotic_arm.rm_get_arm_software_info(robot_handle, &software_info);
//     if (result == 0) {
//         printf("================== Arm Software Information ==================\n");
//         printf("Arm Model:  %s\n", software_info.product_version);
//         printf("Algorithm Library Version:  %s\n", software_info.algorithm_info.version);
//         printf("Control Layer Software Version:  %s\n", software_info.ctrl_info.version);
//         printf("Dynamics Version:  %s\n", software_info.dynamic_info.model_version);
//         printf("Planning Layer Software Version:  %s\n", software_info.plan_info.version);
//         printf("==============================================================\n");
//     }

//     float joint_angles_start[ARM_DOF] = {0.0, 20, 70.0, 0.0, 90.0, 0.0};
//     robotic_arm.rm_movej(robot_handle, joint_angles_start, 20, 0, 0, 1);

//     rm_pose_t pose_movej_p = {{0.3, 0, 0.3}, {0, 0, 0, 0}, {3.14, 0, 0}};
//     robotic_arm.rm_movej_p(robot_handle, pose_movej_p, 20, 0, 0, 1);

//     rm_pose_t pose = {{0.2, 0, 0.3}, {0, 0, 0, 0}, {3.14, 0, 0}};
//     robotic_arm.rm_movel(robot_handle, pose, 20, 0, 0, 1);

//     rm_pose_t pose_movej_p2 = {{0.3, 0, 0.3}, {0, 0, 0, 0}, {3.14, 0, 0}};
//     robotic_arm.rm_movej_p(robot_handle, pose_movej_p2, 20, 0, 0, 1);

//     rm_pose_t pose_via = {{0.2, 0.05, 0.3}, {0, 0, 0, 0}, {3.14, 0, 0}};
//     rm_pose_t pose_to = {{0.2, -0.05, 0.3}, {0, 0, 0, 0}, {3.14, 0, 0}};
//     robotic_arm.rm_movec(robot_handle, pose_via, pose_to, 20, 2, 0, 0, 1);


// }

#include "rm_interface.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc,char **argv)
{   
        //设置灵巧手各手指动作

    rm_set_log_call_back(NULL,3);
    rm_init(RM_TRIPLE_MODE_E);

    char *version = rm_api_version();
    printf("current api version: %s\n", version);

    rm_robot_handle *robot_handle = rm_create_robot_arm("192.168.1.18",8080);

    if( robot_handle->id  == -1)
    {
        rm_delete_robot_arm(robot_handle);
        printf("arm connect err...\n");
    }
    else if(robot_handle != NULL)
    {
        printf("arm id %d \n", robot_handle->id);
    }
    
        //关闭末端接口板RS485端口
    int ret;
    int port = 1;
    ret = rm_close_modbus_mode (robot_handle,port);
    // rm_arm_software_version_t arm_software_version;
    // ret = rm_get_arm_software_info(robot_handle, &arm_software_version);
    // printf("\n================== Arm Software Information ==================\n");
    // printf("get arm software info result : %d\n", ret);
    // printf("Algorithm Library Version: %s\n", arm_software_version.algorithm_info.version);
    // printf("Control Layer Software Version: %s\n", arm_software_version.ctrl_info.version);
    // printf("Dynamics Version: %s\n", arm_software_version.dynamic_info.model_version);
    // printf("Planning Layer Software Version: %s\n", arm_software_version.plan_info.version);
    // printf("Arm Model: %s\n", arm_software_version.product_version);

    // 高速控制灵巧手，非阻塞模式

    int voltage;
    ret = rm_get_tool_voltage(robot_handle,&voltage);
    printf("get voltage result : %d\n", ret);
    printf("voltage : %d\n", voltage);

        // 高速控制灵巧手，非阻塞模式
// 高速控制灵巧手，非阻塞模式

    //配置通讯端口为末端接口板RS485端口，波特率配置115200，超时时间2百毫秒

    // int baudrate = 115200;
    // int timeout = 2;
    // ret=rm_set_modbus_mode(robot_handle,port,baudrate,timeout);

// 高速控制灵巧手，非阻塞模式
    const int pos[6]= {0,0,0,0,0,0};
    ret = rm_set_hand_follow_pos(robot_handle,pos,0);
    printf("set hand follow pos result : %d\n", ret);



    // rm_peripheral_read_write_params_t params_coils;
    // int data[] =  {255,255,0,0,0,0,255,255,255,255,0,0};
    // params_coils.port = 1;
    // params_coils.address = 1135;
    // params_coils.device = 2;
    // params_coils.num = 6;
    // ret = rm_write_registers(robot_handle,params_coils, data);
    // printf("write registers result : %d\n", ret);



}