#include <string.h>
#include <jni.h>
jstring
Java_com_example_testn_Testn_stringfromTestnJNI(
	JNIEnv *env,jobject thiz	){
#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__x86_64__)
   #define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
   #define ABI "mips64"
#elif defined(__mips__)
   #define ABI "mips"
#elif defined(__aarch64__)
   #define ABI "arm64-v8a"
#else
   #define ABI "unknown"
#endif

	return (*env)->NewStringUTF(env,"HelloWorld,I'm sunyiyan");

}

jint
Java_com_example_testn_Testn_sumformTestnJNI(
JNIEnv *env,jobject obj,jintArray array){

   int sum = 0;
   jsize length=(*env)->GetArrayLength(env,array);
   if(length==0)//防止异常发生，如果是空的需要返回
   return 0;
   jint *pointer =(*env)->GetIntArrayElements(env,array,0);//获取数组指针
   int i;
   for(i=0;i<length;i++)
   {
      sum +=pointer[i];//相加每个素组元素
   }
   (*env)->ReleaseIntArrayElements(env,array,pointer,0);//释放内存
   return sum;
}
