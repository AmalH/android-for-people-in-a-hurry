package pragmatictheories.androidprojects.com.quickup1_customtabs.Adapters;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;

import pragmatictheories.androidprojects.com.quickup1_customtabs.Fragments.FirstFragment;
import pragmatictheories.androidprojects.com.quickup1_customtabs.Fragments.SecondFragment;
import pragmatictheories.androidprojects.com.quickup1_customtabs.Fragments.ThirdFragment;


public class MyTabLayoutAdapter extends FragmentPagerAdapter {

    private int NUM_ITEMS = 3;

        public MyTabLayoutAdapter(FragmentManager fm) {
            super(fm);
        }

    @Override
    public int getCount() {
        return  NUM_ITEMS ;
    }

    @Override
    public Fragment getItem(int position) {
        switch (position) {
            /** because to switch fragments inside a tab we need a root FrameLayout,
             in which we load fragments in each time ( getFragmentManager.replce(root,newFrag) )**/
            case 0:
                return new FirstFragment();
            case 1:
                return new SecondFragment();
            case 2:
                return new ThirdFragment();
            default:
                return null;
        }
    }

    /** needed for fragment refresh **/
    @Override
    public int getItemPosition(Object object) {
        return POSITION_NONE;
    }

}
