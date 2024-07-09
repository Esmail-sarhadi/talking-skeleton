package com.example.last_of_us

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Gravity
import android.view.LayoutInflater
import android.view.Menu
import android.widget.Button
import androidx.appcompat.app.ActionBarDrawerToggle
import androidx.appcompat.app.AppCompatDelegate
import androidx.appcompat.widget.Toolbar
import androidx.core.content.res.ResourcesCompat
import androidx.drawerlayout.widget.DrawerLayout
import com.google.android.material.navigation.NavigationView
import www.sanju.motiontoast.MotionToast

class Partitioning : drawer() {



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);

        val inflater = LayoutInflater.from(this)
        val view = inflater.inflate(R.layout.activity_partitioning,null,false)
        drawerLayout.addView(view,0)


        val buttontop = findViewById<Button>(R.id.topbtn)
        val buttonmiddle = findViewById<Button>(R.id.midbtn)
        val buttonlower = findViewById<Button>(R.id.downbtn)

        buttontop.setOnClickListener {
            val intent = Intent(this, upperPart::class.java)
            startActivity(intent)
            finish()
        }
        buttonmiddle.setOnClickListener {
            val intent = Intent(this, middlePart::class.java)
            startActivity(intent)
            finish()
        }
        buttonlower.setOnClickListener {
            val intent = Intent(this, lowerPart::class.java)
            startActivity(intent)
            finish()
        }
    }
    override fun onBackPressed() {
        if (backPressedTime + 2000 > System.currentTimeMillis()&&drawerLayout.isDrawerOpen(navView)) {
            drawerLayout.closeDrawer(Gravity.RIGHT)
            super.onBackPressed()
            backPressedTime = System.currentTimeMillis()
        }
        else if(backPressedTime + 2000 > System.currentTimeMillis()&&drawerLayout.isDrawerOpen(navView)==false) {
            super.onBackPressed()
            finish()
        }
        else if (drawerLayout.isDrawerOpen(navView)) {
            drawerLayout.closeDrawer(Gravity.RIGHT)
            backPressedTime = System.currentTimeMillis()
        } else {
            MotionToast.darkToast(this,"برای خروج دکمه بازگشت را دوباره فشار دهید! ",
                MotionToast.TOAST_INFO,
                MotionToast.GRAVITY_BOTTOM,
                MotionToast.SHORT_DURATION,
                ResourcesCompat.getFont(this,R.font.iransansbold))
            backPressedTime = System.currentTimeMillis()
        }
    }
}