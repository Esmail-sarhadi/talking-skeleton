package com.example.last_of_us

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.WindowManager
import android.widget.Button
import androidx.appcompat.app.AppCompatDelegate
import androidx.core.content.res.ResourcesCompat
import www.sanju.motiontoast.MotionToast

class Guide : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        setContentView(R.layout.activity_guide)
        val buttonClick = findViewById<Button>(R.id.okbtn)
        buttonClick.setOnClickListener {
            MotionToast.darkToast(this,"ابتدا باید به بلوتوث اسکلت سخنگو متصل شوید ",
                MotionToast.TOAST_SUCCESS,
                MotionToast.GRAVITY_BOTTOM,
                MotionToast.SHORT_DURATION,
                ResourcesCompat.getFont(this,R.font.iransansbold))
            val intent = Intent(this, Partitioning::class.java)
            startActivity(intent)
            finish()
        }
    }
}