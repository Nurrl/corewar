using System;

namespace Ncurse
{
    class NativeMethods
    {
        public readonly Delegates.initscr initscr;
        public readonly Delegates.endwin endwin;
        public readonly Delegates.isendwin isendwin;
        public readonly Delegates.cbreak cbreak;
        public readonly Delegates.nocbreak nocbreak;
        public readonly Delegates.echo echo;
        public readonly Delegates.noecho noecho;
        public readonly Delegates.halfdelay halfdelay;
        public readonly Delegates.raw raw;
        public readonly Delegates.noraw noraw;
        public readonly Delegates.noqiflush noqiflush;
        public readonly Delegates.qiflush qiflush;
        public readonly Delegates.typeahead typeahead;
        public readonly Delegates.timeout timeout;
        public readonly Delegates.wtimeout wtimeout;
        public readonly Delegates.notimeout notimeout;
        public readonly Delegates.keypad keypad;
        public readonly Delegates.meta meta;
        public readonly Delegates.intrflush intrflush;
        public readonly Delegates.clearok clearok;
        public readonly Delegates.idlok idlok;
        public readonly Delegates.idcok idcok;
        public readonly Delegates.immedok immedok;
        public readonly Delegates.leaveok leaveok;
        public readonly Delegates.wsetscrreg wsetscrreg;
        public readonly Delegates.scrollok scrollok;
        public readonly Delegates.nl nl;
        public readonly Delegates.nonl nonl;
        public readonly Delegates.setscrreg setscrreg;
        public readonly Delegates.refresh refresh;
        public readonly Delegates.doupdate doupdate;
        public readonly Delegates.wrefresh wrefresh;
        public readonly Delegates.redrawwin redrawwin;
        public readonly Delegates.wredrawln wredrawln;
        public readonly Delegates.wnoutrefresh wnoutrefresh;
        public readonly Delegates.move move;
        public readonly Delegates.addch addch;
        public readonly Delegates.addstr addstr;
        public readonly Delegates.wmove wmove;
        public readonly Delegates.waddch waddch;
        public readonly Delegates.attron attron;
        public readonly Delegates.attroff attroff;
        public readonly Delegates.attrset attrset;
        public readonly Delegates.getch getch;
        public readonly Delegates.get_wch get_wch;
        public readonly Delegates.ungetch ungetch;
        public readonly Delegates.mvgetch mvgetch;
        public readonly Delegates.has_colors has_colors;
        public readonly Delegates.start_color start_color;
        public readonly Delegates.init_pair init_pair;
        public readonly Delegates.use_default_colors use_default_colors;
        public readonly Delegates.COLOR_PAIRS COLOR_PAIRS;
        //public readonly Delegates.getmouse getmouse;
        //public readonly Delegates.ungetmouse ungetmouse;
        public readonly Delegates.mouseinterval mouseinterval;
        public readonly Delegates.mousemask mousemask;

        public readonly Delegates.subwin subwin;
        public readonly Delegates.box box;
        public readonly Delegates.mvwprintw mvwprintw;
        public readonly Delegates.wprintw wprintw;
        public readonly Delegates.wborder wborder;
        public readonly Delegates.init_color init_color;
        public readonly Delegates.wbkgd wbkgd;
        public readonly Delegates.wattroff wattroff;
        public readonly Delegates.wattron wattron;
        public readonly Delegates.waddstr waddstr;
        public readonly Delegates.curs_set curs_set;
        public readonly Delegates.derwin derwin;
        public readonly Delegates.newwin newwin;
        public readonly Delegates.wclrtoeol wclrtoeol;
        public readonly Delegates.wclear wclear;
        public readonly Delegates.werase werase;

        public UnmanagedLib UnmanagedLibrary;
        public NativeMethods(UnmanagedLib lib)
        {
            UnmanagedLibrary = lib;

            initscr = lib.GetNativeMethodDelegate<Delegates.initscr>("initscr");
            endwin = lib.GetNativeMethodDelegate<Delegates.endwin>("endwin");
            isendwin = lib.GetNativeMethodDelegate<Delegates.isendwin>("isendwin");
            cbreak = lib.GetNativeMethodDelegate<Delegates.cbreak>("cbreak");
            nocbreak = lib.GetNativeMethodDelegate<Delegates.nocbreak>("nocbreak");
            echo = lib.GetNativeMethodDelegate<Delegates.echo>("echo");
            noecho = lib.GetNativeMethodDelegate<Delegates.noecho>("noecho");
            halfdelay = lib.GetNativeMethodDelegate<Delegates.halfdelay>("halfdelay");
            raw = lib.GetNativeMethodDelegate<Delegates.raw>("raw");
            noraw = lib.GetNativeMethodDelegate<Delegates.noraw>("noraw");
            noqiflush = lib.GetNativeMethodDelegate<Delegates.noqiflush>("noqiflush");
            qiflush = lib.GetNativeMethodDelegate<Delegates.qiflush>("qiflush");
            typeahead = lib.GetNativeMethodDelegate<Delegates.typeahead>("typeahead");
            timeout = lib.GetNativeMethodDelegate<Delegates.timeout>("timeout");
            wtimeout = lib.GetNativeMethodDelegate<Delegates.wtimeout>("wtimeout");
            notimeout = lib.GetNativeMethodDelegate<Delegates.notimeout>("notimeout");
            keypad = lib.GetNativeMethodDelegate<Delegates.keypad>("keypad");
            meta = lib.GetNativeMethodDelegate<Delegates.meta>("meta");
            intrflush = lib.GetNativeMethodDelegate<Delegates.intrflush>("intrflush");
            clearok = lib.GetNativeMethodDelegate<Delegates.clearok>("clearok");
            idlok = lib.GetNativeMethodDelegate<Delegates.idlok>("idlok");
            idcok = lib.GetNativeMethodDelegate<Delegates.idcok>("idcok");
            immedok = lib.GetNativeMethodDelegate<Delegates.immedok>("immedok");
            leaveok = lib.GetNativeMethodDelegate<Delegates.leaveok>("leaveok");
            wsetscrreg = lib.GetNativeMethodDelegate<Delegates.wsetscrreg>("wsetscrreg");
            scrollok = lib.GetNativeMethodDelegate<Delegates.scrollok>("scrollok");
            nl = lib.GetNativeMethodDelegate<Delegates.nl>("nl");
            nonl = lib.GetNativeMethodDelegate<Delegates.nonl>("nonl");
            setscrreg = lib.GetNativeMethodDelegate<Delegates.setscrreg>("setscrreg");
            refresh = lib.GetNativeMethodDelegate<Delegates.refresh>("refresh");
            doupdate = lib.GetNativeMethodDelegate<Delegates.doupdate>("doupdate");
            wrefresh = lib.GetNativeMethodDelegate<Delegates.wrefresh>("wrefresh");
            redrawwin = lib.GetNativeMethodDelegate<Delegates.redrawwin>("redrawwin");
            wredrawln = lib.GetNativeMethodDelegate<Delegates.wredrawln> ("wredrawln");
            wnoutrefresh = lib.GetNativeMethodDelegate<Delegates.wnoutrefresh>("wnoutrefresh");
            move = lib.GetNativeMethodDelegate<Delegates.move>("move");
            addch = lib.GetNativeMethodDelegate<Delegates.addch>("addch");
            addstr = lib.GetNativeMethodDelegate<Delegates.addstr>("addstr");
            wmove = lib.GetNativeMethodDelegate<Delegates.wmove>("wmove");
            waddch = lib.GetNativeMethodDelegate<Delegates.waddch>("waddch");
            attron = lib.GetNativeMethodDelegate<Delegates.attron>("attron");
            attroff = lib.GetNativeMethodDelegate<Delegates.attroff>("attroff");
            attrset = lib.GetNativeMethodDelegate<Delegates.attrset>("attrset");
            getch = lib.GetNativeMethodDelegate<Delegates.getch>("getch");
            get_wch = lib.GetNativeMethodDelegate<Delegates.get_wch>("get_wch");
            ungetch = lib.GetNativeMethodDelegate<Delegates.ungetch>("ungetch");
            mvgetch = lib.GetNativeMethodDelegate<Delegates.mvgetch>("mvgetch");
            has_colors = lib.GetNativeMethodDelegate<Delegates.has_colors>("has_colors");
            start_color = lib.GetNativeMethodDelegate<Delegates.start_color>("start_color");
            init_pair = lib.GetNativeMethodDelegate<Delegates.init_pair>("init_pair");
            use_default_colors = lib.GetNativeMethodDelegate<Delegates.use_default_colors>("use_default_colors");
            COLOR_PAIRS = lib.GetNativeMethodDelegate<Delegates.COLOR_PAIRS>("COLOR_PAIRS");
            //getmouse = lib.GetNativeMethodDelegate<Delegates.getmouse>("getmouse");
            //ungetmouse = lib.GetNativeMethodDelegate<Delegates.ungetmouse>("ungetmouse");
            mouseinterval = lib.GetNativeMethodDelegate<Delegates.mouseinterval>("mouseinterval");
            mousemask = lib.GetNativeMethodDelegate<Delegates.mousemask>("mousemask");

            subwin = lib.GetNativeMethodDelegate<Delegates.subwin>("subwin");
            box = lib.GetNativeMethodDelegate<Delegates.box>("box");
            mvwprintw = lib.GetNativeMethodDelegate<Delegates.mvwprintw>("mvwprintw");
            wprintw = lib.GetNativeMethodDelegate<Delegates.wprintw>("wprintw");
            wborder = lib.GetNativeMethodDelegate<Delegates.wborder>("wborder");
            init_color = lib.GetNativeMethodDelegate<Delegates.init_color>("init_color");
            wattron = lib.GetNativeMethodDelegate<Delegates.wattron>("wattron");
            wattroff = lib.GetNativeMethodDelegate<Delegates.wattroff>("wattroff");
            wbkgd = lib.GetNativeMethodDelegate<Delegates.wbkgd>("wbkgd");
            waddstr = lib.GetNativeMethodDelegate<Delegates.waddstr>("waddstr");
            curs_set = lib.GetNativeMethodDelegate<Delegates.curs_set>("curs_set");
            derwin = lib.GetNativeMethodDelegate<Delegates.derwin>("derwin");
            newwin = lib.GetNativeMethodDelegate<Delegates.newwin>("newwin");
            wclrtoeol = lib.GetNativeMethodDelegate<Delegates.wclrtoeol>("wclrtoeol");
            wclear = lib.GetNativeMethodDelegate<Delegates.wclear>("wclear");
            werase = lib.GetNativeMethodDelegate<Delegates.werase>("werase");
        }
    }
}
