#include <jni.h>
#include <string>

using namespace std;

//region Hello from India
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativeapikeys_MainActivity_firstApiKey(
        JNIEnv *env,
        jobject /* this */) {
    string api_key = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918";
    return env->NewStringUTF(api_key.c_str());
}
//endregion

//region Divided into parts
string calculatePartTwo() {
    return std::to_string(20000 + 9000 + 72);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativeapikeys_MainActivity_secondApiKey(JNIEnv *env, jobject thiz) {
    string part_1 = "33516d05f9aa";
    string part_2 = calculatePartTwo();
    string part_3 = "b9f61f95c14c251e8ffcff2f2a3aa649cbfd7c1c1440cd2";

    string api_key = part_1 + part_2 + part_3;

    return env->NewStringUTF(api_key.c_str());
}
//endregion

//region Encrypted

string decrypt(string encrypted) {
    char key = 'X';
    string output = encrypted;

    for (int i = 0; i < encrypted.size(); i++)
        output[i] = encrypted[i] ^ key;

    return output;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativeapikeys_MainActivity_thirdApiKey(JNIEnv *env, jobject thiz) {
    string encrypted_api_key = "o=j>mhl::9m;<<nj<o<j9==hhiik;h>9a`m=<n=`h;==aimnj`m=kno`:j9lii;>";
    string api_key = decrypt(encrypted_api_key);

    return env->NewStringUTF(api_key.c_str());
}
//endregion
