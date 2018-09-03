package pragmatictheories.androidprojects.com.quickup1_customtabs;

import android.content.res.Resources;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.os.Bundle;
import android.support.design.widget.TabLayout;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.util.TypedValue;
import android.view.View;
import android.widget.LinearLayout;

import java.lang.reflect.Field;

import pragmatictheories.androidprojects.com.quickup1_customtabs.Adapters.MyTabLayoutAdapter;

public class MainActivity extends AppCompatActivity {

    private static TabLayout tablayout;
    private static ViewPager vpPager;
    private MyTabLayoutAdapter adapter;
    private static ColorMatrixColorFilter filter;
    private ColorMatrix matrix;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /** will be used to change tab icons colors on select/deselect */
        matrix = new ColorMatrix();
        matrix.setSaturation(0);
        filter = new ColorMatrixColorFilter(matrix);

        /*** setting the tabsLayout ***/
        adapter = new MyTabLayoutAdapter(getSupportFragmentManager());
        vpPager = findViewById(R.id.viewpager);
        vpPager.setAdapter(adapter);
        vpPager.setCurrentItem(0);
        vpPager.setOffscreenPageLimit(3);
        tablayout=findViewById(R.id.tabsLayout);
        tablayout.setupWithViewPager(vpPager);
        setUpTabIcons(tablayout);

        /** setting padding to the tab indicator **/
        tablayout.post(new Runnable() {
            @Override
            public void run() {
                setTabIndicator(tablayout,10,10);
            }
        });

        /**  setting/removing tab color filter on selection **/
        tablayout.setOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                tab.getIcon().clearColorFilter();
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {
                tab.getIcon().setColorFilter(filter);
            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {
            }
        });

    }

    private static void setUpTabIcons(TabLayout tbs){
        tbs.getTabAt(0).setIcon(R.drawable.ic_food);
        tbs.getTabAt(1).setIcon(R.drawable.ic_music);
        tbs.getTabAt(2).setIcon(R.drawable.ic_sports);
        allTabIconsToDeselected(tbs);
    }

       private void setTabIndicator (TabLayout tabs, int leftDip, int rightDip){
        Class<?> tabLayout = tabs.getClass();
        Field tabStrip = null;
        try {
            tabStrip = tabLayout.getDeclaredField("mTabStrip");
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }

        tabStrip.setAccessible(true);
        LinearLayout llTab = null;
        try {
            llTab = (LinearLayout) tabStrip.get(tabs);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

        int left = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, leftDip, Resources.getSystem().getDisplayMetrics());
        int right = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, rightDip, Resources.getSystem().getDisplayMetrics());

        for (int i = 0; i < llTab.getChildCount(); i++) {
            View child = llTab.getChildAt(i);
            child.setPadding(0, 0, 0, 0);
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 1);
            params.leftMargin = left;
            params.rightMargin = right;
            child.setLayoutParams(params);
            child.invalidate();
        }
    }

    private static void allTabIconsToDeselected(TabLayout tablayout){
        for(int i=1;i<3;i++){
            tablayout.getTabAt(i).getIcon().setColorFilter(filter);
        }
    }
}
