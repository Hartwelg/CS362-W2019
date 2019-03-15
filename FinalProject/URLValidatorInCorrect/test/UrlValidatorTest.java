

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
      // Manual testing: each write 10 urls of the format assertTrue(isValid(URL)==result)
      // You can use this function to implement your manual testing	   
      
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

      String[] validSchemes = {"http://", "https://", "ftp://", "h3t://", "ssh://"};// TODO: add 3 more schemes each
      String[] validAuthorities = {"www.google.com", "www.ebay.com", "tinyurl.com", "oregonstate.edu"}; // TODO: add 3 more authorities each
      String[] validPorts = {"", ":120", ":80", ":65535", ":640"};             // TODO: add 3 more ports each
      String[] validPaths = {"/$41", "/test", "/path/test", "/one/two/three/four"};                 // TODO: add 3 more valid paths each 
      String[] validQueries = {"?action=view", "", "?action=edit&mode=up"}        // TODO: add 2 valid queries each
      for(scheme:validSchemes){
         for(auth:validAuthorities){
            for(port:validPorts){
               for(path:validPaths){
                  for(query:validQueries){
                     String testURL = scheme + auth + port + path + query;
                     assertTrue(isValid(testURL));
                  }
               }
            }
         }
      }
   }

    public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing
        String[] validSchemes = {"http://", "https://", "", "ftp://", "h3t://", "ssh://"};// TODO: add 3 more schemes each
        String[] validAuthorities = {"www.google.com", "www.yahoo.com", "www.worldtangsoodo.com", "ebay.com", "google.com", "oregonstate.edu"}; // TODO: add 3 more authorities each
        String[] validPorts = {"", ":120", ":640", ":80", ":1000", ":65535"};             // TODO: add 3 more ports each
        String[] validPaths = {"/$41", "/error", "/software/htp/cics/index.html"};                 // TODO: add 3 more valid paths each
        String[] validQueries = {"?action=view", "", "?action=edit&mode=up"};        // TODO: add 2 valid queries each
        String[] invalidSchemes = {"errno", "ftp:", "://", "./", "../", "ssh"};       // TODO: add 3 more schemes each
        String[] invalidAuthorities = {"badname.badname", ".com.google", "none", "this.that", "co.co.", "..."};   // TODO: add 3 more authorities each
        String[] invalidPorts = {"0", ":1000222", ":port", "..", "badport", "999999999"};         // TODO: add 3 more ports each
        String[] invalidPaths = {"//", "path??", "probablybadlol///", "/test//", "path/test/../.", "badpath"};         // TODO: add 3 more valid paths each
        String[] invalidQueries = {"xyz::#$%^", "badquery", "???"};        // TODO: add 2 more queries each
        // build 5 strings with only one invalid part for each invalid part, make sure that full string is invalid
        for(scheme:invalidSchemes){
            for(auth:invalidAuthorities){
                for(port:invalidPorts){
                    for(path:invalidPaths){
                        for(query:invalidQueries){
                            String testURL = scheme    + validAuthorities[(int) (Math.random() *validAuthorities.length)]
                                    + validPorts[(int) (Math.random() *validPorts.length)]
                                    + validPaths[(int) (Math.random() *validPaths.length)]
                                    + validQueries[(int) (Math.random() *validQueries.length)] ;
                            assertTrue(isValid(testURL) == false);
                            testURL = validSchemes[(int) (Math.random() *validSchemes.length)]
                                    + auth
                                    + validPorts[(int) (Math.random() *validPorts.length)]
                                    + validPaths[(int) (Math.random() *validPaths.length)]
                                    + validQueries[(int) (Math.random() *validQueries.length)] ;
                            assertTrue(isValid(testURL) == false);
                            testURL = validSchemes[(int) (Math.random() *validSchemes.length)]
                                    + validAuthorities[(int) (Math.random() *validAuthorities.length)]
                                    + port
                                    + validPaths[(int) (Math.random() *validPaths.length)]
                                    + validQueries[(int) (Math.random() *validQueries.length)] ;
                            assertTrue(isValid(testURL) == false);
                            testURL = validSchemes[(int) (Math.random() *validSchemes.length)]
                                    + validAuthorities[(int) (Math.random() *validAuthorities.length)]
                                    + validPorts[(int) (Math.random() *validPorts.length)]
                                    + path
                                    + validQueries[(int) (Math.random() *validQueries.length)] ;
                            assertTrue(isValid(testURL) == false);
                            testURL = validSchemes[(int) (Math.random() *validSchemes.length)]
                                    + validAuthorities[(int) (Math.random() *validAuthorities.length)]
                                    + validPorts[(int) (Math.random() *validPorts.length)]
                                    + validPaths[(int) (Math.random() *validPaths.length)]
                                    + query;
                            assertTrue(isValid(testURL) == false);
                        }
                    }
                }
            }
        }
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
	   String[] testPathOptions = {"/test", "/test/file", "./", "/.", ""};
	   String[] testQueries = {"", "?action=view", "?action=edit&mode=up"};
	   
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
}
