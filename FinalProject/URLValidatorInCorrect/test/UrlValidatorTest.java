

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
      // Manual testing: each write 10 urls of the format assertTrue(isValid(URL)==result)
      // You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
      //You can use this function to implement your First Partition testing

      String[] validSchemes = {"http://", "https://"};// TODO: add 3 more schemes each
      String[] validAuthorities = {"www.google.com"}; // TODO: add 3 more authorities each
      String[] validPorts = {"", ":120"};             // TODO: add 3 more ports each
      String[] validPaths = {"/$41"};                 // TODO: add 3 more valid paths each 
      String[] validQueries = {"?action=view"}        // TODO: add 2 valid queries each
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
        String[] validSchemes = {"http://", "https://", ""};// TODO: add 3 more schemes each
        String[] validAuthorities = {"www.google.com", "www.yahoo.com", "www.worldtangsoodo.com"}; // TODO: add 3 more authorities each
        String[] validPorts = {"", ":120", ":640"};             // TODO: add 3 more ports each
        String[] validPaths = {"/$41", "/error", "/software/htp/cics/index.html"};                 // TODO: add 3 more valid paths each
        String[] validQueries = {"?action=view"}        // TODO: add 2 valid queries each
        String[] invalidSchemes = {"errno", "ftp:", "://"};       // TODO: add 3 more schemes each
        String[] invalidAuthorities = {"badname.badname", ".com.google", "none"};   // TODO: add 3 more authorities each
        String[] invalidPorts = {"0", ":1000222", ":port"};         // TODO: add 3 more ports each
        String[] invalidPaths = {"//", "path??", "probablybadlol///"};         // TODO: add 3 more valid paths each
        String[] invalidQueries = {"xyz::#$%^"}        // TODO: add 2 more queries each
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
   {  // unit test cases that implement various methods to test different URLS
	   // You can use this function for programming based testing

   }
   


}
