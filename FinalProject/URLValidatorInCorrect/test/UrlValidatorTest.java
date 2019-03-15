

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	         UrlValidator validator = new UrlValidator();
      
      assertTrue(validator.isValid("http://www.github.com") == true;
      assertTrue(validator.isValid("http://:0/test1?action=view") == false;
      assertTrue(validator.isValid("www.github.com") == true;
      assertTrue(validator.isValid("www.google") == false;
      assertTrue(validator.isValid("www.google.com:65535/test1/?action=edit&mode=up") ==true ;
      assertTrue(validator.isValid("255.255.255.255") == true;
      assertTrue(validator.isValid("1.2.3.4") == true;
      assertTrue(validator.isValid("1.2.3.4.0") == false;
      assertTrue(validator.isValid("1.2.3.4:0") == true;
      assertTrue(validator.isValid("weibfdjwncwev") == false;
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
