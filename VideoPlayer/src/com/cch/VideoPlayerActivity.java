package com.cch;
/*
import android.app.Activity;
import android.os.Bundle;

public class VideoPlayerActivity extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }
}
*/
import android.app.Activity;
import android.net.Uri;
import android.os.Bundle;
import android.widget.MediaController;
import android.widget.Toast;
import android.widget.VideoView;

public class VideoPlayerActivity extends Activity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        VideoView videoView =(VideoView)findViewById(R.id.videoView);
        MediaController mediaController= new MediaController(this);
        mediaController.setAnchorView(videoView);        
        Uri uri=Uri.parse("android.resource://"+getPackageName()+"/"+R.raw.hello);        
        videoView.setMediaController(mediaController);
        videoView.setVideoURI(uri);        
        videoView.requestFocus();
        videoView.start();
    } 
}
