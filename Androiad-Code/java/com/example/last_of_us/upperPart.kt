package com.example.last_of_us


import android.content.Intent
import android.os.Bundle
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuItem

import androidx.appcompat.app.AppCompatDelegate


class upperPart : drawer() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        val inflater = LayoutInflater.from(this)
        val view6 = inflater.inflate(R.layout.activity_upper_part,null,false)
        drawerLayout.addView(view6,0)
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