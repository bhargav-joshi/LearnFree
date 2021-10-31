package com.spring.bo;

import org.springframework.stereotype.Component;

import com.spring.model.Item;

//use appropriate annotation
@Component
public class ItemBO {
	
	/* This method should estimate the total netPrice and return the same to the ItemService class */
	public double calculateNetPrice (Item iObj) 
	{
		double netPrice=0.0;
		// fill the code
		double gst=0;
		String itemCategory=iObj.getItemCategory();
		netPrice=iObj.getPrice();
		
		switch (itemCategory) {
		case "Dairies":
			gst=0.0;
			
			break;
		case "Medicines":
			gst=0.05;
			
			break;
		case "Electricals":
			gst=0.12;
			
			break;
		case "Cosmetics":
			gst=0.18;
			
			break;
		
			//break;
		}
		
		double gstAmount=(iObj.getPrice()*gst);
		if(gstAmount==0)
		{
			return netPrice;
		}
		else {
			netPrice=netPrice+gstAmount;
			return netPrice;
		}
	}

}
package com.spring.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

//use appropriate annotation
@Configuration
@ComponentScan({"com.spring.bo","com.spring.service","com.spring.model"})
public class ApplicationConfig
{

}
package com.spring.main;
import java.util.Scanner;
import java.*;
import javax.security.auth.login.AppConfigurationEntry;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import com.spring.config.ApplicationConfig;
import com.spring.service.ItemService;

public class Driver {

	public static void main(String[] args) {
		
		Scanner in=new Scanner(System.in);
		// fill the code
		System.out.println("Enter the Item Name:");
		String itemName= in.nextLine();
				System.out.println("Enter the Item Category:");
		String itemCategory=in.nextLine();
		System.out.println("Enter the Price:");
		double price=in.nextDouble();
		ApplicationContext ctx=new AnnotationConfigApplicationContext(ApplicationConfig.class);
		  ItemService eObj=  (ItemService)ctx.getBean("itemService");
         double netPrice=eObj.calculateNetPrice(itemName, itemCategory, price);
         System.out.println("Net Price is RS: "+netPrice);

	}

}
package com.spring.model;

import org.springframework.stereotype.Component;

//use appropriate annotation
@Component
public class Item {
	
	private String itemName;
	private String itemCategory;
	private double price;
	private int gstPercentage;
	public String getItemName() {
		return itemName;
	}
	public void setItemName(String itemName) {
		this.itemName = itemName;
	}
	public String getItemCategory() {
		return itemCategory;
	}
	public void setItemCategory(String itemCategory) {
		this.itemCategory = itemCategory;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getGstPercentage() {
		return gstPercentage;
	}
	public void setGstPercentage(int gstPercentage) {
		this.gstPercentage = gstPercentage;
	}
	
}
package com.spring.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.stereotype.Component;

import com.spring.bo.ItemBO;
import com.spring.config.ApplicationConfig;
import com.spring.model.Item;

//use appropriate annotation
@Component
public class ItemService {
	
	private ItemBO itemBOObj;

	@Autowired
	public ItemService(ItemBO itemBOObj) {
		super();
		this.itemBOObj = itemBOObj;
	}
	public ItemBO getItemBOObj() {
		return itemBOObj;
	}

	public void setItemBOObj(ItemBO itemBOObj) {
		this.itemBOObj = itemBOObj;
	}

	//use appropriate annotation
	
	
	/* This method has to assign the values of itemName, itemCategory, price, gstPercentage to the Item object iObj 
	and invoke calculateNetPrice method in ItemBO class by passing Item object iObj */
	
	public double calculateNetPrice (String itemName, String itemCategory, double price)
	{
		double netPrice=0.0;
		ApplicationContext ctx=new AnnotationConfigApplicationContext(ApplicationConfig.class);
		Item iObj=(Item)ctx.getBean("item");
		// fill the code
		iObj.setItemName(itemName);
		iObj.setItemCategory(itemCategory);
		iObj.setPrice(price);
		
		netPrice=itemBOObj.calculateNetPrice(iObj);
		return netPrice;
	}

	

}
