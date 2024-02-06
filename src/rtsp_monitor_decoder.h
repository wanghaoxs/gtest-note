////
//// Created by hao.wang on 2024/1/31.
////
//
// #ifndef RTSP_APP_RTSP_MONITOR_DECODER_H
// #define RTSP_APP_RTSP_MONITOR_DECODER_H
//
// #include "common.h"
//
// class MonitorDecoderTask {
// public:
//    int channel_id{};
//    std::string component = "MonitorDecoder";
//    CUvideodec* vpu_decoder{};
//
//    int period_interval_seconds{5};
//
//    MonitorDecoderTask(int channelId, CUvideodec* pVpuDecoder) {
//        this->channel_id = channelId;
//        this->vpu_decoder = pVpuDecoder;
//    }
//
//    [[noreturn]] void operator()() const {
//        INFO("MonitorDecoder TID:" + std::to_string(syscall(SYS_gettid)), channel_id, component);
//        CUVIDGETDECODESTATUS decoder_status{};
//        CUresult cuResult{};
//        while (true) {
//            if (*vpu_decoder) {
//                cuResult = cuvidGetDecodeStatus(*vpu_decoder, &decoder_status);
//                if (cuResult == CUDA_SUCCESS) {
//                    INFO("decodeStatus is [" + std::to_string(decoder_status.decodeStatus) + "]", channel_id,
//                         component);
//                } else {
//                    ERROR("cuvidGetDecodeStatus failed !!! [" + RTSPUtil::get_vpu_error_name(cuResult) + "]",
//                          channel_id, component);
//                }
//            } else {
//                INFO("vpu_decoder is nullptr !!!", channel_id, component);
//            }
//
//            std::this_thread::sleep_for(std::chrono::seconds(period_interval_seconds));
//        }
//    }
//};
//
// #endif  // RTSP_APP_RTSP_MONITOR_DECODER_H
