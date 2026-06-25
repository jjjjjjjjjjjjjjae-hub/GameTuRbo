#include <jni.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

extern "C" JNIEXPORT jlong JNICALL
Java_com_gameturbo_core_Memory_readLong(JNIEnv *env, jobject thiz, jint pid, jlong address) {
    long value = 0;
    struct iovec local = {&value, sizeof(value)};
    struct iovec remote = {(void *)address, sizeof(value)};
    process_vm_readv(pid, &local, 1, &remote, 1, 0);
    return value;
}

extern "C" JNIEXPORT void JNICALL
Java_com_gameturbo_core_Memory_writeFloat(JNIEnv *env, jobject thiz, jint pid, jlong address, jfloat value) {
    struct iovec local = {&value, sizeof(value)};
    struct iovec remote = {(void *)address, sizeof(value)};
    process_vm_writev(pid, &local, 1, &remote, 1, 0);
}
