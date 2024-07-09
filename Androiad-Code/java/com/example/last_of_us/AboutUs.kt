package com.example.last_of_us

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import androidx.appcompat.app.AppCompatDelegate
import androidx.core.content.res.ResourcesCompat
import www.sanju.motiontoast.MotionToast

class AboutUs : drawer() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO)
        val inflater = LayoutInflater.from(this)
        val view1 = inflater.inflate(R.layout.activity_about_us,null,false)
        drawerLayout.addView(view1,0)
        val information = findViewById<Button>(R.id.more_information1)
        information.setOnClickListener {
            val browserIntent = Intent(Intent.ACTION_VIEW, Uri.parse("https://sanasmartlife.ir/about-us/"))
            startActivity(browserIntent)
        }
    }
    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        menuInflater.inflate(R.menu.main, menu)
        return true
    }
    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        val id = item.itemId
        if (id==R.id.action_settings){
            val intent = Intent(this, Partitioning::class.java)
            startActivity(intent)
            finish()
        }
        return super.onOptionsItemSelected(item)
    }
    override fun onBackPressed() {
        val intent = Intent(this, Partitioning::class.java)
        startActivity(intent)
        finish()
    }

}