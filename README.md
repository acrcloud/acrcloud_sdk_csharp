# Audio Recognition C# SDK

## Overview
  [ACRCloud](https://www.acrcloud.com/) provides [Automatic Content Recognition](https://www.acrcloud.com/docs/introduction/automatic-content-recognition/) services for [Audio Fingerprinting](https://www.acrcloud.com/docs/introduction/audio-fingerprinting/) based applications such as **[Audio Recognition](https://www.acrcloud.com/music-recognition)** (supports music, video, ads for both online and offline), **[Broadcast Monitoring](https://www.acrcloud.com/broadcast-monitoring)**, **[Second Screen](https://www.acrcloud.com/second-screen-synchronization)**, **[Copyright Protection](https://www.acrcloud.com/copyright-protection-de-duplication)** and etc.<br>
  
  This **audio recognition C# SDK** support most of audio / video files. 

>>Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...<br>
>>Video: mp4, mkv, wmv, flv, ts, avi ...

## Requirements
Follow one of the tutorials to create a project and get your host, access_key and access_secret.

 * [How to identify songs by sound](https://www.acrcloud.com/docs/tutorials/identify-music-by-sound/)
 
 * [How to detect custom audio content by sound](https://www.acrcloud.com/docs/tutorials/identify-audio-custom-content/)
 
## Windows Runtime Library 
**If you run the SDK on Windows, you must install this library.**<br>
X86: [download and install Library(vcredist_x86.exe)](https://www.microsoft.com/en-us/download/details.aspx?id=5555)<br>
x64: [download and install Library(vcredist_x64.exe)](https://www.microsoft.com/en-us/download/details.aspx?id=14632)

## Note
1. You must not modify package name "com.acrcloud.utils".<br>
2. If you run the SDK on Windows, you must install library(vcredist).
3. If you are developing C++ project, also can use "libacrcloud_extr_tool.dll"

## Functions
Introduction all API.
### recognizer.cs
```c
class ACRCloudRecognizer
{
  public String RecognizeByFile(String filePath, int startSeconds);
    /**
      *
      *  recognize by file path of (Audio/Video file)
      *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
      *          Video: mp4, mkv, wmv, flv, ts, avi ...
      *
      *  @param filePath query file path
      *  @param startSeconds skip (startSeconds) seconds from from the beginning of (filePath)
      *  
      *  @return result metainfos https://docs.acrcloud.com/metadata
      *
      **/
      
  public String RecognizeByFileBuffer(byte[] fileBuffer, int fileBufferLen, int startSeconds);
    /**
      *
      *  recognize by buffer of (Audio/Video file)
      *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
      *          Video: mp4, mkv, wmv, flv, ts, avi ...
      *
      *  @param fileBuffer query buffer
      *  @param fileBufferLen the length of fileBufferLen 
      *  @param startSeconds skip (startSeconds) seconds from from the beginning of fileBuffer
      *  
      *  @return result metainfos https://docs.acrcloud.com/metadata
      *
      **/
      
  public string Recognize(byte[] wavAudioBuffer, int wavAudioBufferLen);
    /**
      *
      *  recognize by wav audio buffer(RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, mono 8000 Hz) 
      *
      *  @param wavAudioBuffer query audio buffer
      *  @param wavAudioBufferLen the length of wavAudioBuffer
      *  
      *  @return result metainfos https://docs.acrcloud.com/metadata
      *
      **/
}


class ACRCloudExtrTool {
  public byte[] CreateFingerprint(byte[] pcmBuffer, int pcmBufferLen, bool isDB);
   /**
    *
    *  create "ACRCloud Fingerprint" by wav audio buffer(RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, mono 8000 Hz) 
    *
    *  @param pcmBuffer query audio buffer
    *  @param pcmBufferLen the length of wavAudioBuffer
    *  @param isDB   If it is True, it will create db frigerprint; 
    *  
    *  @return result "ACRCloud Fingerprint"
    *
    **/
    
  public byte[] CreateFingerprintByFile(string filePath, int startTimeSeconds, int audioLenSeconds, bool isDB);
   /**
    *
    *  create "ACRCloud Fingerprint" by file path of (Audio/Video file)
    *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
    *          Video: mp4, mkv, wmv, flv, ts, avi ...
    *
    *  @param filePath query file path
    *  @param startTimeSeconds skip (startSeconds) seconds from from the beginning of (filePath)
    *  @param audioLenSeconds Length of audio data you need. if you create recogize frigerprint, default is 12 seconds, if you create db frigerprint, it is not usefully; 
    *  @param isDB   If it is True, it will create db frigerprint; 
    *  
    *  @return result "ACRCloud Fingerprint"
    *
    **/
    
  public byte[] CreateFingerprintByFileBuffer(byte[] fileBuffer, int fileBufferLen, int startTimeSeconds, int audioLenSeconds, bool isDB)
  /**
    *
    *  create "ACRCloud Fingerprint" by file buffer of (Audio/Video file)
    *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
    *          Video: mp4, mkv, wmv, flv, ts, avi ...
    *
    *  @param fileBuffer data buffer of input file
    *  @param fileBufferLen  length of fileBuffer
    *  @param startTimeSeconds skip (startSeconds) seconds from from the beginning of (filePath)
    *  @param audioLenSeconds Length of audio data you need. if you create recogize frigerprint, default is 12 seconds, if you create db frigerprint, it is not usefully; 
    *  @param isDB   If it is True, it will create db frigerprint; 
    *  
    *  @return result "ACRCloud Fingerprint"
    *
    **/
    
  public byte[] DecodeAudioByFile(string filePath, int startTimeSeconds, int audioLenSeconds);
    /**
      *
      *  decode audio from file path of (Audio/Video file)
      *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
      *          Video: mp4, mkv, wmv, flv, ts, avi ...
      *
      *  @param filePath query file path
      *  @param startTimeSeconds skip (startSeconds) seconds from from the beginning of (filePath)
      *  @param audioLenSeconds Length of audio data you need, if it is 0, will decode all the audio;  
      *  
      *  @return result audio data(formatter:RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, mono 8000 Hz)
      *
      **/
      
  public byte[] DecodeAudioByFileBuffer(byte[] fileBuffer, int fileBufferLen, int startTimeSeconds, int audioLenSeconds)
    /**
      *
      *  decode audio from file buffer of (Audio/Video file)
      *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
      *          Video: mp4, mkv, wmv, flv, ts, avi ...
      *
      *  @param fileBuffer data buffer of input file
      *  @param fileBufferLen  length of fileBuffer
      *  @param startTimeSeconds skip (startSeconds) seconds from from the beginning of (filePath)
      *  @param audioLenSeconds Length of audio data you need, if it is 0, will decode all the audio;  
      *  
      *  @return result audio data(formatter:RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, mono 8000 Hz)
      *
      **/

  /**
    *
    *  get duration from file buffer of (Audio/Video file)
    *          Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
    *          Video: mp4, mkv, wmv, flv, ts, avi ...
    *
    *  @param filePath query file path 
    *  
    *  @return duration ms
    *
    **/
   public int GetDurationMillisecondByFile(string filePath)
  }
  
```

## Example
ACRCloudRecognitionTest is a VS2010 Project.<br>
You need to replace "XXXXXXXX" below with your project's host, access_key and access_secret, and run it.
```c
void Main(string[] args)
    {
        var config = new Dictionary<string, object>();
        config.Add("host", "XXXXXXX");
        config.Add("access_key", "XXXXXXXX");
        config.Add("access_secret", "XXXXXXXX");
        config.Add("timeout", 10); // seconds

        /**
          *   
          *  recognize by file path of (Formatter: Audio/Video)
          *     Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
          *     Video: mp4, mkv, wmv, flv, ts, avi ...
          *     
          * 
         **/
        ACRCloudRecognizer re = new ACRCloudRecognizer(config);

        // It will skip 80 seconds from the beginning of test.mp3.
        string result = re.RecognizeByFile("test.mp3", 80);
        Console.WriteLine(result);

        using (FileStream fs = new FileStream(@"test.mp3", FileMode.Open))
        {
            using (BinaryReader reader = new BinaryReader(fs))
            {
                byte[] datas = reader.ReadBytes((int)fs.Length);
                // It will skip 80 seconds from the beginning of datas.
                result = re.RecognizeByFileBuffer(datas, datas.Length, 80);               
                Console.WriteLine(result);
            }
        }
```
