package com.example.last_of_us



import android.annotation.SuppressLint
import android.content.ActivityNotFoundException
import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatDelegate


class ContactUs : drawer() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        val inflater = LayoutInflater.from(this)
        val view2 = inflater.inflate(R.layout.activity_contact_us,null,false)
        drawerLayout.addView(view2,0)
        val information = findViewById<Button>(R.id.more_information2)
        val information2 = findViewById<TextView>(R.id.contact_us1)
        val information3 = findViewById<TextView>(R.id.contact_us2)
        val whtasup = findViewById<ImageView>(R.id.whatsuap)
        val instagram = findViewById<ImageView>(R.id.instagram)
        information.setOnClickListener {
            val browserIntent = Intent(Intent.ACTION_VIEW, Uri.parse("https://sanasmartlife.ir/contact-us/"))
            startActivity(browserIntent)
        }
        information2.setOnClickListener {
            call()
        }
        whtasup.setOnClickListener {
            startSupportChat()
        }

        instagram.setOnClickListener {
            val uri = Uri.parse("http://instagram.com/_u/sanasmartlife")
            val likeIng = Intent(Intent.ACTION_VIEW, uri)

            likeIng.setPackage("com.instagram.android")

            try {
                startActivity(likeIng)
            } catch (e: ActivityNotFoundException) {
                startActivity(
                    Intent(
                        Intent.ACTION_VIEW,
                        Uri.parse("http://instagram.com/sanasmartlife")
                    )
                )
            }
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
    private fun startSupportChat() {
        try {
            val headerReceiver = "" // Replace with your message.
            val bodyMessageFormal = "" // Replace with your message.
            val whatsappContain = headerReceiver + bodyMessageFormal
            val trimToNumner = "+989232519556" //10 digit number
            val intent = Intent(Intent.ACTION_VIEW)
            intent.data = Uri.parse("https://wa.me/$trimToNumner/?text=")
            startActivity(intent)
        } catch (e: java.lang.Exception) {
            e.printStackTrace()
        }
    }
    fun call() {
        val dialIntent = Intent(Intent.ACTION_DIAL)
        dialIntent.data = Uri.parse("tel:" + "09232519556")
        startActivity(dialIntent)
    }
}