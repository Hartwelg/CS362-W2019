

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
	   UrlValidator validator = new UrlValidator();
//You can use this function to implement your manual testing	   
	   assertTrue(validator.isValid("http://www.google.com") == true);
	   assertTrue(validator.isValid("http://www.ebay.com") == true);
	   assertTrue(validator.isValid("https://www.com") == false);
	   assertTrue(validator.isValid("h3t:..") == false);
	   assertTrue(validator.isValid("http:") == false);
	   assertTrue(validator.isValid("www.google.com") == true);
	   assertTrue(validator.isValid("") == false);
	   assertTrue(validator.isValid("http://www.google.com:80/test/t") == true);
	   assertTrue(validator.isValid("ftp://www.duckduckgo.com:40000/temp/test") == true);
	   assertTrue(validator.isValid("ftp://www.google.com") == true);
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
	   String[] testSchemes = {"http://", "https://", "ftp://", "h3t://", "ssh://", ""};
	   String[] badTestSchemes = {"http", "h3t", "htp", "fes:", "ssh"};
	   String[] testAuthorities = {"www.google.com", "www.ebay.com", "example.url", , "www.ex.url.", "this.that.com.", "255.255.255.255",  "10.0.0.1", ""};
	   String[] badTestAuthorities = {"www.com", "www", "dot.com", "this.that", "256.255.255.255"};
	   String[] testPorts = {"80", "0", "65535", "1", ""};
	   String[] badTestPorts = {"65555", "99999999", "70000"};
	   String[] testPaths = {"/test", ,  "/test/file",  "/$", ""};
	   String[] badTestPaths = {"t", ".t.", "/t/", "/that//"};
	   String[] testQueries = {"", "?action=view", "?action=edit&mode=up"};
	   String[] badTestQueries = {"...", "a;slkd"};
	   
	   int i;
	   for (i = 0; i < testSchemes.length; i++)
	   {
		   assertTrue(isValidScheme(testSchemes[i]) == true);
	   }
	   for (i = 0; i < badTestSchemes.length; i++)
	   {
		   assertTrue(isValidScheme(badTestSchemes[i]) == false);
	   }
	   for (i = 0; i < testAuthorities.length; i++)
	   {
		   assertTrue(isValidAuthority(testAuthorities[i]) == true);
	   }
	   for (i = 0; i < badTestAuthorities.length; i++)
	   {
		   assertTrue(isValidAuthority(badTestAuthorities[i]) == false);
	   }
	   for (i = 0; i < testPorts.length; i++)
	   {
		   assertTrue(isValidPort(testPorts[i]) == true);
	   }
	   for (i = 0; i < badTestPorts.length; i++)
	   {
		   assertTrue(isValidPort(badTestPorts[i]) == false);
	   }
	   for (i = 0; i < testPaths.length; i++)
	   {
		   assertTrue(isValidPath(testPaths[i]) == true);
	   }
	   for (i = 0; i < testQueries.length; i++)
	   {
		   assertTrue(isValidQuery(testQueries[i]) == true);
	   }
	   for (i = 0; i < badTestQueries.length; i++)
	   {
		   assertTrue(isValidQuery(badTestQueries[i]) == false);
	   }
   }
   


}
