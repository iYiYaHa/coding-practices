class SolutionA {
    public String replaceSpace(String s) {
        // Note that using StringBuilder is faster since there 
        // is no cost for thread-safe.
        StringBuffer sb = new StringBuffer();
        for(int i = 0;i < s.length();++i){
            if(s.charAt(i) == ' ')
                sb.append("%20");
            else
                sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}

