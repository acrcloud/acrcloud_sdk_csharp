# acrcloud_sdk_CSharp
Create "ACRCloud Fingerprint" by Audio/Video file, and use "ACRCloud Fingerprint" to recognize metainfos by "ACRCloud webapi".<br>

# ACRCloud
Docs: [https://docs.acrcloud.com/](https://docs.acrcloud.com/)<br>
Console: [https://console.acrcloud.com/](https://console.acrcloud.com/)

# Overview
This module can recognize ACRCloud by most of audio/video file.<br>
>>>>Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...<br>
>>>>Video: mp4, mkv, wmv, flv, ts, avi ...

# Functions
Introduction all API.
## recognizer.cs
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
  }
  
```

# Example
ACRCloudRecognitionTest is a VS2010 Project.<br>
You can replace "XXXXXXXX" below with your project's access_key and access_secret, and run it.
```c
void Main(string[] args)
    {
        var config = new Dictionary<string, object>();
        config.Add("host", "ap-southeast-1.api.acrcloud.com");
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
