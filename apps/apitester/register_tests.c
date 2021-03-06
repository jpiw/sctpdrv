/* This files is created automatically by the Makefile. */

#include "api_tests.h"

DECLARE_APITEST(sctp_recvmsg, rd_compl);
DECLARE_APITEST(sctp_recvmsg, rd_incompl);
DECLARE_APITEST(sctp_recvmsg, msg_peek_in);
DECLARE_APITEST(sctp_recvmsg, msg_eor_in);
DECLARE_APITEST(sctp_recvmsg, msg_notification_in);
DECLARE_APITEST(sctp_sendmsg, c_p_c_a);
DECLARE_APITEST(sctp_sendmsg, c_p_c_a_over);
DECLARE_APITEST(sctp_sendmsg, w_p_c_a);
DECLARE_APITEST(sctp_sendmsg, w_p_c_a_over);
DECLARE_APITEST(sctp_sendmsg, c_p_w_a);
DECLARE_APITEST(sctp_sendmsg, c_p_w_a_over);
DECLARE_APITEST(sctp_sendmsg, w_p_w_a);
DECLARE_APITEST(sctp_sendmsg, w_p_w_a_over);
DECLARE_APITEST(sctp_sendmsg, b_p_c_a);
DECLARE_APITEST(sctp_sendmsg, b_p_c_a_over);
DECLARE_APITEST(sctp_sendmsg, c_p_b_a);
DECLARE_APITEST(sctp_sendmsg, c_p_b_a_over);
DECLARE_APITEST(sctp_sendmsg, b_p_b_a);
DECLARE_APITEST(sctp_sendmsg, b_p_b_a_over);
DECLARE_APITEST(sctp_sendmsg, w_p_b_a);
DECLARE_APITEST(sctp_sendmsg, w_p_b_a_over);
DECLARE_APITEST(sctp_sendmsg, b_p_w_a);
DECLARE_APITEST(sctp_sendmsg, b_p_w_a_over);
DECLARE_APITEST(sctp_sendmsg, non_null_zero);
DECLARE_APITEST(sctp_sendmsg, non_null_zero_over);
DECLARE_APITEST(sctp_sendmsg, null_zero);
DECLARE_APITEST(sctp_sendmsg, null_zero_over);
DECLARE_APITEST(sctp_sendmsg, null_non_zero);
DECLARE_APITEST(sctp_sendmsg, null_non_zero_over);
DECLARE_APITEST(sctp_sendmsg, large_addrlen);
DECLARE_APITEST(sctp_sendmsg, short_addrlen);
DECLARE_APITEST(rtoinfo, gso_1_1_defaults);
DECLARE_APITEST(rtoinfo, gso_1_M_defaults);
DECLARE_APITEST(rtoinfo, gso_1_1_bad_id);
DECLARE_APITEST(rtoinfo, gso_1_M_bad_id);
DECLARE_APITEST(rtoinfo, sso_1_1_good);
DECLARE_APITEST(rtoinfo, sso_1_M_good);
DECLARE_APITEST(rtoinfo, sso_1_1_bad_id);
DECLARE_APITEST(rtoinfo, sso_1_M_bad_id);
DECLARE_APITEST(rtoinfo, sso_1_1_init);
DECLARE_APITEST(rtoinfo, sso_1_M_init);
DECLARE_APITEST(rtoinfo, sso_1_1_max);
DECLARE_APITEST(rtoinfo, sso_1_M_max);
DECLARE_APITEST(rtoinfo, sso_1_1_min);
DECLARE_APITEST(rtoinfo, sso_1_M_min);
DECLARE_APITEST(rtoinfo, sso_1_1_same);
DECLARE_APITEST(rtoinfo, sso_1_M_same);
DECLARE_APITEST(rtoinfo, sso_ill_1);
DECLARE_APITEST(rtoinfo, sso_ill_2);
DECLARE_APITEST(rtoinfo, sso_ill_3);
DECLARE_APITEST(rtoinfo, sso_ill_4);
DECLARE_APITEST(rtoinfo, sso_ill_5);
DECLARE_APITEST(rtoinfo, sso_ill_6);
DECLARE_APITEST(rtoinfo, gso_1_1_c_bad_id);
DECLARE_APITEST(rtoinfo, sso_1_1_c_bad_id);
DECLARE_APITEST(rtoinfo, sso_1_1_inherit);
DECLARE_APITEST(rtoinfo, sso_1_M_inherit);
DECLARE_APITEST(assoclist, gso_numbers_zero);
DECLARE_APITEST(assoclist, gso_numbers_pos);
DECLARE_APITEST(assoclist, gso_ids_no_assoc);
DECLARE_APITEST(assoclist, gso_ids_buf_fit);
DECLARE_APITEST(assoclist, gso_ids_buf_large);
DECLARE_APITEST(assoclist, gso_ids_buf_small);
DECLARE_APITEST(associnfo, gso_1_1_defaults);
DECLARE_APITEST(associnfo, gso_1_M_defaults);
DECLARE_APITEST(associnfo, sso_rxt_1_1);
DECLARE_APITEST(associnfo, sso_rxt_1_M);
DECLARE_APITEST(associnfo, sso_rxt_asoc_1_1);
DECLARE_APITEST(associnfo, sso_rxt_asoc_1_M);
DECLARE_APITEST(associnfo, sso_rxt_asoc_1_1_inherit);
DECLARE_APITEST(associnfo, sso_rxt_asoc_1_M_inherit);
DECLARE_APITEST(associnfo, sso_clife_1_1);
DECLARE_APITEST(associnfo, sso_clife_1_M);
DECLARE_APITEST(associnfo, sso_clife_asoc_1_1);
DECLARE_APITEST(associnfo, sso_clife_asoc_1_M);
DECLARE_APITEST(associnfo, sso_clife_asoc_1_1_inherit);
DECLARE_APITEST(associnfo, sso_clife_asoc_1_M_inherit);
DECLARE_APITEST(associnfo, sso_lrwnd_ep_1_1);
DECLARE_APITEST(associnfo, sso_lrwnd_ep_1_M);
DECLARE_APITEST(associnfo, sso_lrwnd_asoc_1_1);
DECLARE_APITEST(associnfo, sso_lrwnd_asoc_1_M);
DECLARE_APITEST(associnfo, sso_prwnd_asoc_1_1);
DECLARE_APITEST(associnfo, sso_prwnd_asoc_1_M);
DECLARE_APITEST(associnfo, sso_pdest_asoc_1_1);
DECLARE_APITEST(associnfo, sso_pdest_asoc_1_M);
DECLARE_APITEST(initmsg, gso_1_1_defaults);
DECLARE_APITEST(initmsg, gso_1_M_defaults);
DECLARE_APITEST(initmsg, gso_1_1_set_ostrm);
DECLARE_APITEST(initmsg, gso_1_1_set_istrm);
DECLARE_APITEST(initmsg, gso_1_1_set_max);
DECLARE_APITEST(initmsg, gso_1_1_set_timeo);
DECLARE_APITEST(initmsg, gso_1_M_set_ostrm);
DECLARE_APITEST(initmsg, gso_1_M_set_istrm);
DECLARE_APITEST(initmsg, gso_1_M_set_max);
DECLARE_APITEST(initmsg, gso_1_M_set_timeo);
DECLARE_APITEST(nodelay, gso_1_1_def_ndelay);
DECLARE_APITEST(nodelay, gso_1_M_def_ndelay);
DECLARE_APITEST(nodelay, gso_1_1_set_ndelay);
DECLARE_APITEST(nodelay, gso_1_M_set_ndelay);
DECLARE_APITEST(autoclose, gso_1_1_def_autoclose);
DECLARE_APITEST(autoclose, gso_1_M_def_autoclose);
DECLARE_APITEST(autoclose, gso_1_1_set_autoclose);
DECLARE_APITEST(autoclose, gso_1_M_set_autoclose);
DECLARE_APITEST(setpeerprim, sso_1_1_good_peerprim);
DECLARE_APITEST(setpeerprim, sso_1_1_bad_peerprim);
DECLARE_APITEST(setpeerprim, sso_1_M_good_peerprim);
DECLARE_APITEST(setpeerprim, sso_1_M_bad_peerprim);
DECLARE_APITEST(setprim, gso_1_1_get_prim);
DECLARE_APITEST(setprim, gso_1_M_get_prim);
DECLARE_APITEST(setprim, sso_1_1_set_prim);
DECLARE_APITEST(setprim, sso_1_M_set_prim);
DECLARE_APITEST(setprim, sso_1_1_bad_prim);
DECLARE_APITEST(setprim, sso_1_M_bad_prim);
DECLARE_APITEST(adaptation, gso_1_1);
DECLARE_APITEST(adaptation, gso_1_M);
DECLARE_APITEST(adaptation, sso_1_1);
DECLARE_APITEST(adaptation, sso_1_M);
DECLARE_APITEST(disfrag, gso_def_1_1);
DECLARE_APITEST(disfrag, gso_def_1_M);
DECLARE_APITEST(disfrag, sso_1_1);
DECLARE_APITEST(disfrag, sso_1_M);
DECLARE_APITEST(paddrpara, gso_def_1_1);
DECLARE_APITEST(paddrpara, gso_def_1_M);
DECLARE_APITEST(paddrpara, sso_hb_int_1_1);
DECLARE_APITEST(paddrpara, sso_hb_int_1_M);
DECLARE_APITEST(paddrpara, sso_hb_zero_1_1);
DECLARE_APITEST(paddrpara, sso_hb_zero_1_M);
DECLARE_APITEST(paddrpara, sso_hb_off_1_1);
DECLARE_APITEST(paddrpara, sso_hb_off_1_M);
DECLARE_APITEST(paddrpara, sso_hb_on_1_1);
DECLARE_APITEST(paddrpara, sso_hb_on_1_M);
DECLARE_APITEST(paddrpara, sso_pmrxt_int_1_1);
DECLARE_APITEST(paddrpara, sso_pmrxt_int_1_M);
DECLARE_APITEST(paddrpara, sso_bad_hb_en_1_1);
DECLARE_APITEST(paddrpara, sso_bad_hb_en_1_M);
DECLARE_APITEST(paddrpara, sso_bad_pmtud_en_1_1);
DECLARE_APITEST(paddrpara, sso_bad_pmtud_en_1_M);
DECLARE_APITEST(paddrpara, sso_ahb_int_1_1);
DECLARE_APITEST(paddrpara, sso_ahb_int_1_M);
DECLARE_APITEST(paddrpara, sso_ahb_zero_1_1);
DECLARE_APITEST(paddrpara, sso_ahb_zero_1_M);
DECLARE_APITEST(paddrpara, sso_ahb_off_1_1);
DECLARE_APITEST(paddrpara, sso_ahb_off_1_M);
DECLARE_APITEST(paddrpara, sso_ahb_on_1_1);
DECLARE_APITEST(paddrpara, sso_ahb_on_1_M);
DECLARE_APITEST(paddrpara, sso_apmrxt_int_1_1);
DECLARE_APITEST(paddrpara, sso_apmrxt_int_1_M);
DECLARE_APITEST(paddrpara, sso_apmtu_dis_1_1);
DECLARE_APITEST(paddrpara, sso_apmtu_dis_1_M);
DECLARE_APITEST(paddrpara, sso_av6_flo_1_1);
DECLARE_APITEST(paddrpara, sso_av6_flo_1_M);
DECLARE_APITEST(paddrpara, sso_av4_tos_1_1);
DECLARE_APITEST(paddrpara, sso_av4_tos_1_M);
DECLARE_APITEST(paddrpara, sso_ainhhb_int_1_1);
DECLARE_APITEST(paddrpara, sso_ainhhb_int_1_M);
DECLARE_APITEST(paddrpara, sso_ainhhb_zero_1_1);
DECLARE_APITEST(paddrpara, sso_ainhhb_zero_1_M);
DECLARE_APITEST(paddrpara, sso_ainhhb_off_1_1);
DECLARE_APITEST(paddrpara, sso_ainhhb_off_1_M);
DECLARE_APITEST(paddrpara, sso_ainhpmrxt_int_1_1);
DECLARE_APITEST(paddrpara, sso_ainhpmrxt_int_1_M);
DECLARE_APITEST(paddrpara, sso_dhb_int_1_1);
DECLARE_APITEST(paddrpara, sso_dhb_int_1_M);
DECLARE_APITEST(paddrpara, sso_dhb_zero_1_1);
DECLARE_APITEST(paddrpara, sso_dhb_zero_1_M);
DECLARE_APITEST(paddrpara, sso_dhb_off_1_1);
DECLARE_APITEST(paddrpara, sso_dhb_off_1_M);
DECLARE_APITEST(paddrpara, sso_dpmrxt_int_1_1);
DECLARE_APITEST(paddrpara, sso_dpmrxt_int_1_M);
DECLARE_APITEST(paddrpara, sso_dav4_tos_1_1);
DECLARE_APITEST(paddrpara, sso_dav4_tos_1_M);
DECLARE_APITEST(paddrpara, sso_hb_demand_1_1);
DECLARE_APITEST(paddrpara, sso_hb_demand_1_M);
DECLARE_APITEST(defsend, gso_def_1_1);
DECLARE_APITEST(defsend, gso_def_1_M);
DECLARE_APITEST(defsend, sso_on_1_1);
DECLARE_APITEST(defsend, sso_on_1_M);
DECLARE_APITEST(defsend, sso_asc_1_1);
DECLARE_APITEST(defsend, sso_asc_1_M);
DECLARE_APITEST(defsend, sso_inherit_1_1);
DECLARE_APITEST(defsend, sso_inherit_1_M);
DECLARE_APITEST(defsend, sso_inherit_ncep_1_1);
DECLARE_APITEST(defsend, sso_inherit_ncep_1_M);
DECLARE_APITEST(defsend, sso_nc_other_asc_1_M);
DECLARE_APITEST(events, gso_def_1_1);
DECLARE_APITEST(events, gso_def_1_M);
DECLARE_APITEST(events, sso_1_1);
DECLARE_APITEST(events, sso_1_M);
DECLARE_APITEST(mapped, gso_1_1_def);
DECLARE_APITEST(mapped, gso_1_M_def);
DECLARE_APITEST(mapped, sso_1_1);
DECLARE_APITEST(mapped, sso_1_M);
DECLARE_APITEST(mapped, sso_bad_1_1);
DECLARE_APITEST(mapped, sso_bad_1_M);
DECLARE_APITEST(maxseg, gso_def_1_1);
DECLARE_APITEST(maxseg, sso_set_1_1);
DECLARE_APITEST(maxseg, gso_def_1_M);
DECLARE_APITEST(maxseg, sso_set_1_M);
DECLARE_APITEST(maxseg, sso_asc_1_1);
DECLARE_APITEST(maxseg, sso_asc_1_M);
DECLARE_APITEST(maxseg, sso_inherit_1_1);
DECLARE_APITEST(maxseg, sso_inherit_1_M);
DECLARE_APITEST(maxseg, sso_inherit_ncep_1_1);
DECLARE_APITEST(maxseg, sso_inherit_ncep_1_M);
DECLARE_APITEST(maxseg, sso_nc_other_asc_1_M);
DECLARE_APITEST(authchk, gso_1_1);
DECLARE_APITEST(authchk, gso_1_M);
DECLARE_APITEST(authchk, sso_1_1);
DECLARE_APITEST(authchk, sso_1_M);
DECLARE_APITEST(hmacid, sso_1_1);
DECLARE_APITEST(hmacid, sso_1_M);
DECLARE_APITEST(hmacid, sso_bad_1_1);
DECLARE_APITEST(hmacid, sso_bad_1_M);
DECLARE_APITEST(hmacid, sso_nosha1_1_1);
DECLARE_APITEST(hmacid, sso_nosha1_1_M);
DECLARE_APITEST(authkey, gso_def_1_1);
DECLARE_APITEST(authkey, gso_def_1_M);
DECLARE_APITEST(authkey, gso_new_1_1);
DECLARE_APITEST(authkey, gso_new_1_M);
DECLARE_APITEST(authkey, sso_def_1_1);
DECLARE_APITEST(authkey, sso_def_1_M);
DECLARE_APITEST(authkey, sso_new_1_1);
DECLARE_APITEST(authkey, sso_new_1_M);
DECLARE_APITEST(authkey, sso_newnul_1_1);
DECLARE_APITEST(authkey, sso_newnul_1_M);
DECLARE_APITEST(authkey, gso_a_def_1_1);
DECLARE_APITEST(authkey, gso_a_def_1_M);
DECLARE_APITEST(authkey, sso_a_def_1_1);
DECLARE_APITEST(authkey, sso_a_def_1_M);
DECLARE_APITEST(authkey, sso_a_new_1_1);
DECLARE_APITEST(authkey, sso_a_new_1_M);
DECLARE_APITEST(authkey, sso_a_newnul_1_1);
DECLARE_APITEST(authkey, sso_a_newnul_1_M);
DECLARE_APITEST(actkey, gso_def_1_1);
DECLARE_APITEST(actkey, gso_def_1_M);
DECLARE_APITEST(actkey, sso_def_1_1);
DECLARE_APITEST(actkey, sso_def_1_M);
DECLARE_APITEST(actkey, sso_inval_1_1);
DECLARE_APITEST(actkey, sso_inval_1_M);
DECLARE_APITEST(actkey, sso_new_1_1);
DECLARE_APITEST(actkey, sso_new_1_M);
DECLARE_APITEST(actkey, sso_inhdef_1_1);
DECLARE_APITEST(actkey, sso_inhdef_1_M);
DECLARE_APITEST(actkey, sso_inhnew_1_1);
DECLARE_APITEST(actkey, sso_inhnew_1_M);
DECLARE_APITEST(actkey, sso_achg_1_1);
DECLARE_APITEST(actkey, sso_achg_1_M);
DECLARE_APITEST(delkey, gso_def_1_1);
DECLARE_APITEST(delkey, gso_def_1_M);
DECLARE_APITEST(delkey, gso_inval_1_1);
DECLARE_APITEST(delkey, gso_inval_1_M);
DECLARE_APITEST(delkey, sso_def_1_1);
DECLARE_APITEST(delkey, sso_def_1_M);
DECLARE_APITEST(delkey, sso_inval_1_1);
DECLARE_APITEST(delkey, sso_inval_1_M);
DECLARE_APITEST(delkey, sso_new_1_1);
DECLARE_APITEST(delkey, sso_new_1_M);
DECLARE_APITEST(delkey, sso_newact_1_1);
DECLARE_APITEST(delkey, sso_newact_1_M);
DECLARE_APITEST(delkey, sso_zero_1_1);
DECLARE_APITEST(delkey, sso_zero_1_M);
DECLARE_APITEST(dsack, gso_def_1_1);
DECLARE_APITEST(dsack, gso_def_1_M);
DECLARE_APITEST(dsack, sso_delay_1_1);
DECLARE_APITEST(dsack, sso_delay_1_M);
DECLARE_APITEST(dsack, sso_freq_1_1);
DECLARE_APITEST(dsack, sso_freq_1_M);
DECLARE_APITEST(dsack, sso_asc_1_1);
DECLARE_APITEST(dsack, sso_asc_1_M);
DECLARE_APITEST(dsack, sso_inherit_1_1);
DECLARE_APITEST(dsack, sso_inherit_1_M);
DECLARE_APITEST(dsack, sso_inherit_ncep_1_1);
DECLARE_APITEST(dsack, sso_inherit_ncep_1_M);
DECLARE_APITEST(dsack, sso_nc_other_asc_1_M);
DECLARE_APITEST(fraginter, gso_def_1_1);
DECLARE_APITEST(fraginter, gso_def_1_M);
DECLARE_APITEST(fraginter, sso_1_1);
DECLARE_APITEST(fraginter, sso_1_M);
DECLARE_APITEST(fraginter, sso_bad_1_1);
DECLARE_APITEST(fraginter, sso_bad_1_M);
DECLARE_APITEST(pdapi, gso_1_1);
DECLARE_APITEST(pdapi, gso_1_M);
DECLARE_APITEST(padapi, sso_1_1);
DECLARE_APITEST(pdapi, sso_1_M);
DECLARE_APITEST(xrcvinfo, sso_1_1);
DECLARE_APITEST(xrcvinfo, sso_1_M);
DECLARE_APITEST(aasconf, sso_1_1);
DECLARE_APITEST(aasconf, sso_1_M);
DECLARE_APITEST(maxburst, gso_def_1_1);
DECLARE_APITEST(maxburst, gso_def_1_M);
DECLARE_APITEST(maxburst, sso_1_1);
DECLARE_APITEST(maxburst, sso_1_M);
DECLARE_APITEST(context, sso_1_1);
DECLARE_APITEST(context, sso_1_M);
DECLARE_APITEST(context, sso_asc_1_1);
DECLARE_APITEST(context, sso_asc_1_M);
DECLARE_APITEST(context, sso_inherit_1_1);
DECLARE_APITEST(context, sso_inherit_1_M);
DECLARE_APITEST(context, sso_inherit_ncep_1_1);
DECLARE_APITEST(context, sso_inherit_ncep_1_M);
DECLARE_APITEST(context, sso_nc_other_asc_1_M);
DECLARE_APITEST(eeor, sso_1_1);
DECLARE_APITEST(eeor, sso_1_M);
DECLARE_APITEST(read, status);
DECLARE_APITEST(read, paddrinfo);
DECLARE_APITEST(read, auth_p_chklist);
DECLARE_APITEST(read, auth_l_chklist);
DECLARE_APITEST(reuseport, set_1_to_M);
DECLARE_APITEST(reuseport, get_1_to_M);
DECLARE_APITEST(reuseport, set_before_bind);
DECLARE_APITEST(reuseport, get_default);
DECLARE_APITEST(reuseport, get_after_set);
DECLARE_APITEST(reuseport, set_after_bind);
DECLARE_APITEST(reuseport, set_after_bindx);
DECLARE_APITEST(reuseport, bind_twice);
DECLARE_APITEST(reuseport, bind_twice_illegal_1);
DECLARE_APITEST(reuseport, bind_twice_illegal_2);
DECLARE_APITEST(reuseport, bind_twice_listen);
DECLARE_APITEST(reuseport, bind_subset);
DECLARE_APITEST(reuseport, listen_twice);
DECLARE_APITEST(reuseport, accept_inheritage);
DECLARE_APITEST(reuseport, connect);
DECLARE_APITEST(connect, non_listen);
DECLARE_APITEST(connect, listen);
DECLARE_APITEST(connect, self_non_listen);
DECLARE_APITEST(connect, self_listen);
DECLARE_APITEST(bind, port_s_a_s_p);
DECLARE_APITEST(bind, v4tov6_s_a_s_p);
DECLARE_APITEST(bind, v4tov6_w_a_s_p);
DECLARE_APITEST(bind, v4tov6only_w_a);
DECLARE_APITEST(bind, v4tov6only_s_a);
DECLARE_APITEST(bind, same_port_s_a_s_p);
DECLARE_APITEST(bind, duplicate_s_a_s_p);
DECLARE_APITEST(bind, refinement);
DECLARE_APITEST(bindx, port_w_a_w_p);
DECLARE_APITEST(bindx, port_s_a_w_p);
DECLARE_APITEST(bindx, port_w_a_s_p);
DECLARE_APITEST(bindx, port_s_a_s_p);
DECLARE_APITEST(bindx, zero_flag);
DECLARE_APITEST(bindx, add_zero_addresses);
DECLARE_APITEST(bindx, rem_zero_addresses);
DECLARE_APITEST(bindx, add_zero_addresses_NULL);
DECLARE_APITEST(bindx, rem_zero_addresses_NULL);
DECLARE_APITEST(bindx, add_null_addresses);
DECLARE_APITEST(bindx, rem_null_addresses);
DECLARE_APITEST(bindx, dup_add_s_a_s_p);
DECLARE_APITEST(bindx, rem_last_s_a_s_p);
DECLARE_APITEST(bindx, rem_s_a_s_p);
DECLARE_APITEST(shutdown, 1toM_RD);
DECLARE_APITEST(shutdown, 1toM_WR);
DECLARE_APITEST(shutdown, 1toM_RDWR);
DECLARE_APITEST(shutdown, 1to1_not_connected);
DECLARE_APITEST(socket, ipv4_1to1);
DECLARE_APITEST(socket, ipv4_1toM);
DECLARE_APITEST(socket, ipv6_1to1);
DECLARE_APITEST(socket, ipv6_1toM);

struct test all_tests[] = {
    REGISTER_APITEST(sctp_recvmsg, rd_compl),
    REGISTER_APITEST(sctp_recvmsg, rd_incompl),
    REGISTER_APITEST(sctp_recvmsg, msg_peek_in),
    REGISTER_APITEST(sctp_recvmsg, msg_eor_in),
    REGISTER_APITEST(sctp_recvmsg, msg_notification_in),
    REGISTER_APITEST(sctp_sendmsg, c_p_c_a),
    REGISTER_APITEST(sctp_sendmsg, c_p_c_a_over),
    REGISTER_APITEST(sctp_sendmsg, w_p_c_a),
    REGISTER_APITEST(sctp_sendmsg, w_p_c_a_over),
    REGISTER_APITEST(sctp_sendmsg, c_p_w_a),
    REGISTER_APITEST(sctp_sendmsg, c_p_w_a_over),
    REGISTER_APITEST(sctp_sendmsg, w_p_w_a),
    REGISTER_APITEST(sctp_sendmsg, w_p_w_a_over),
    REGISTER_APITEST(sctp_sendmsg, b_p_c_a),
    REGISTER_APITEST(sctp_sendmsg, b_p_c_a_over),
    REGISTER_APITEST(sctp_sendmsg, c_p_b_a),
    REGISTER_APITEST(sctp_sendmsg, c_p_b_a_over),
    REGISTER_APITEST(sctp_sendmsg, b_p_b_a),
    REGISTER_APITEST(sctp_sendmsg, b_p_b_a_over),
    REGISTER_APITEST(sctp_sendmsg, w_p_b_a),
    REGISTER_APITEST(sctp_sendmsg, w_p_b_a_over),
    REGISTER_APITEST(sctp_sendmsg, b_p_w_a),
    REGISTER_APITEST(sctp_sendmsg, b_p_w_a_over),
    REGISTER_APITEST(sctp_sendmsg, non_null_zero),
    REGISTER_APITEST(sctp_sendmsg, non_null_zero_over),
    REGISTER_APITEST(sctp_sendmsg, null_zero),
    REGISTER_APITEST(sctp_sendmsg, null_zero_over),
    REGISTER_APITEST(sctp_sendmsg, null_non_zero),
    REGISTER_APITEST(sctp_sendmsg, null_non_zero_over),
    REGISTER_APITEST(sctp_sendmsg, large_addrlen),
    REGISTER_APITEST(sctp_sendmsg, short_addrlen),
    REGISTER_APITEST(rtoinfo, gso_1_1_defaults),
    REGISTER_APITEST(rtoinfo, gso_1_M_defaults),
    REGISTER_APITEST(rtoinfo, gso_1_1_bad_id),
    REGISTER_APITEST(rtoinfo, gso_1_M_bad_id),
    REGISTER_APITEST(rtoinfo, sso_1_1_good),
    REGISTER_APITEST(rtoinfo, sso_1_M_good),
    REGISTER_APITEST(rtoinfo, sso_1_1_bad_id),
    REGISTER_APITEST(rtoinfo, sso_1_M_bad_id),
    REGISTER_APITEST(rtoinfo, sso_1_1_init),
    REGISTER_APITEST(rtoinfo, sso_1_M_init),
    REGISTER_APITEST(rtoinfo, sso_1_1_max),
    REGISTER_APITEST(rtoinfo, sso_1_M_max),
    REGISTER_APITEST(rtoinfo, sso_1_1_min),
    REGISTER_APITEST(rtoinfo, sso_1_M_min),
    REGISTER_APITEST(rtoinfo, sso_1_1_same),
    REGISTER_APITEST(rtoinfo, sso_1_M_same),
    REGISTER_APITEST(rtoinfo, sso_ill_1),
    REGISTER_APITEST(rtoinfo, sso_ill_2),
    REGISTER_APITEST(rtoinfo, sso_ill_3),
    REGISTER_APITEST(rtoinfo, sso_ill_4),
    REGISTER_APITEST(rtoinfo, sso_ill_5),
    REGISTER_APITEST(rtoinfo, sso_ill_6),
    REGISTER_APITEST(rtoinfo, gso_1_1_c_bad_id),
    REGISTER_APITEST(rtoinfo, sso_1_1_c_bad_id),
    REGISTER_APITEST(rtoinfo, sso_1_1_inherit),
    REGISTER_APITEST(rtoinfo, sso_1_M_inherit),
    REGISTER_APITEST(assoclist, gso_numbers_zero),
    REGISTER_APITEST(assoclist, gso_numbers_pos),
    REGISTER_APITEST(assoclist, gso_ids_no_assoc),
    REGISTER_APITEST(assoclist, gso_ids_buf_fit),
    REGISTER_APITEST(assoclist, gso_ids_buf_large),
    REGISTER_APITEST(assoclist, gso_ids_buf_small),
    REGISTER_APITEST(associnfo, gso_1_1_defaults),
    REGISTER_APITEST(associnfo, gso_1_M_defaults),
    REGISTER_APITEST(associnfo, sso_rxt_1_1),
    REGISTER_APITEST(associnfo, sso_rxt_1_M),
    REGISTER_APITEST(associnfo, sso_rxt_asoc_1_1),
    REGISTER_APITEST(associnfo, sso_rxt_asoc_1_M),
    REGISTER_APITEST(associnfo, sso_rxt_asoc_1_1_inherit),
    REGISTER_APITEST(associnfo, sso_rxt_asoc_1_M_inherit),
    REGISTER_APITEST(associnfo, sso_clife_1_1),
    REGISTER_APITEST(associnfo, sso_clife_1_M),
    REGISTER_APITEST(associnfo, sso_clife_asoc_1_1),
    REGISTER_APITEST(associnfo, sso_clife_asoc_1_M),
    REGISTER_APITEST(associnfo, sso_clife_asoc_1_1_inherit),
    REGISTER_APITEST(associnfo, sso_clife_asoc_1_M_inherit),
    REGISTER_APITEST(associnfo, sso_lrwnd_ep_1_1),
    REGISTER_APITEST(associnfo, sso_lrwnd_ep_1_M),
    REGISTER_APITEST(associnfo, sso_lrwnd_asoc_1_1),
    REGISTER_APITEST(associnfo, sso_lrwnd_asoc_1_M),
    REGISTER_APITEST(associnfo, sso_prwnd_asoc_1_1),
    REGISTER_APITEST(associnfo, sso_prwnd_asoc_1_M),
    REGISTER_APITEST(associnfo, sso_pdest_asoc_1_1),
    REGISTER_APITEST(associnfo, sso_pdest_asoc_1_M),
    REGISTER_APITEST(initmsg, gso_1_1_defaults),
    REGISTER_APITEST(initmsg, gso_1_M_defaults),
    REGISTER_APITEST(initmsg, gso_1_1_set_ostrm),
    REGISTER_APITEST(initmsg, gso_1_1_set_istrm),
    REGISTER_APITEST(initmsg, gso_1_1_set_max),
    REGISTER_APITEST(initmsg, gso_1_1_set_timeo),
    REGISTER_APITEST(initmsg, gso_1_M_set_ostrm),
    REGISTER_APITEST(initmsg, gso_1_M_set_istrm),
    REGISTER_APITEST(initmsg, gso_1_M_set_max),
    REGISTER_APITEST(initmsg, gso_1_M_set_timeo),
    REGISTER_APITEST(nodelay, gso_1_1_def_ndelay),
    REGISTER_APITEST(nodelay, gso_1_M_def_ndelay),
    REGISTER_APITEST(nodelay, gso_1_1_set_ndelay),
    REGISTER_APITEST(nodelay, gso_1_M_set_ndelay),
    REGISTER_APITEST(autoclose, gso_1_1_def_autoclose),
    REGISTER_APITEST(autoclose, gso_1_M_def_autoclose),
    REGISTER_APITEST(autoclose, gso_1_1_set_autoclose),
    REGISTER_APITEST(autoclose, gso_1_M_set_autoclose),
    REGISTER_APITEST(setpeerprim, sso_1_1_good_peerprim),
    REGISTER_APITEST(setpeerprim, sso_1_1_bad_peerprim),
    REGISTER_APITEST(setpeerprim, sso_1_M_good_peerprim),
    REGISTER_APITEST(setpeerprim, sso_1_M_bad_peerprim),
    REGISTER_APITEST(setprim, gso_1_1_get_prim),
    REGISTER_APITEST(setprim, gso_1_M_get_prim),
    REGISTER_APITEST(setprim, sso_1_1_set_prim),
    REGISTER_APITEST(setprim, sso_1_M_set_prim),
    REGISTER_APITEST(setprim, sso_1_1_bad_prim),
    REGISTER_APITEST(setprim, sso_1_M_bad_prim),
    REGISTER_APITEST(adaptation, gso_1_1),
    REGISTER_APITEST(adaptation, gso_1_M),
    REGISTER_APITEST(adaptation, sso_1_1),
    REGISTER_APITEST(adaptation, sso_1_M),
    REGISTER_APITEST(disfrag, gso_def_1_1),
    REGISTER_APITEST(disfrag, gso_def_1_M),
    REGISTER_APITEST(disfrag, sso_1_1),
    REGISTER_APITEST(disfrag, sso_1_M),
    REGISTER_APITEST(paddrpara, gso_def_1_1),
    REGISTER_APITEST(paddrpara, gso_def_1_M),
    REGISTER_APITEST(paddrpara, sso_hb_int_1_1),
    REGISTER_APITEST(paddrpara, sso_hb_int_1_M),
    REGISTER_APITEST(paddrpara, sso_hb_zero_1_1),
    REGISTER_APITEST(paddrpara, sso_hb_zero_1_M),
    REGISTER_APITEST(paddrpara, sso_hb_off_1_1),
    REGISTER_APITEST(paddrpara, sso_hb_off_1_M),
    REGISTER_APITEST(paddrpara, sso_hb_on_1_1),
    REGISTER_APITEST(paddrpara, sso_hb_on_1_M),
    REGISTER_APITEST(paddrpara, sso_pmrxt_int_1_1),
    REGISTER_APITEST(paddrpara, sso_pmrxt_int_1_M),
    REGISTER_APITEST(paddrpara, sso_bad_hb_en_1_1),
    REGISTER_APITEST(paddrpara, sso_bad_hb_en_1_M),
    REGISTER_APITEST(paddrpara, sso_bad_pmtud_en_1_1),
    REGISTER_APITEST(paddrpara, sso_bad_pmtud_en_1_M),
    REGISTER_APITEST(paddrpara, sso_ahb_int_1_1),
    REGISTER_APITEST(paddrpara, sso_ahb_int_1_M),
    REGISTER_APITEST(paddrpara, sso_ahb_zero_1_1),
    REGISTER_APITEST(paddrpara, sso_ahb_zero_1_M),
    REGISTER_APITEST(paddrpara, sso_ahb_off_1_1),
    REGISTER_APITEST(paddrpara, sso_ahb_off_1_M),
    REGISTER_APITEST(paddrpara, sso_ahb_on_1_1),
    REGISTER_APITEST(paddrpara, sso_ahb_on_1_M),
    REGISTER_APITEST(paddrpara, sso_apmrxt_int_1_1),
    REGISTER_APITEST(paddrpara, sso_apmrxt_int_1_M),
    REGISTER_APITEST(paddrpara, sso_apmtu_dis_1_1),
    REGISTER_APITEST(paddrpara, sso_apmtu_dis_1_M),
    REGISTER_APITEST(paddrpara, sso_av6_flo_1_1),
    REGISTER_APITEST(paddrpara, sso_av6_flo_1_M),
    REGISTER_APITEST(paddrpara, sso_av4_tos_1_1),
    REGISTER_APITEST(paddrpara, sso_av4_tos_1_M),
    REGISTER_APITEST(paddrpara, sso_ainhhb_int_1_1),
    REGISTER_APITEST(paddrpara, sso_ainhhb_int_1_M),
    REGISTER_APITEST(paddrpara, sso_ainhhb_zero_1_1),
    REGISTER_APITEST(paddrpara, sso_ainhhb_zero_1_M),
    REGISTER_APITEST(paddrpara, sso_ainhhb_off_1_1),
    REGISTER_APITEST(paddrpara, sso_ainhhb_off_1_M),
    REGISTER_APITEST(paddrpara, sso_ainhpmrxt_int_1_1),
    REGISTER_APITEST(paddrpara, sso_ainhpmrxt_int_1_M),
    REGISTER_APITEST(paddrpara, sso_dhb_int_1_1),
    REGISTER_APITEST(paddrpara, sso_dhb_int_1_M),
    REGISTER_APITEST(paddrpara, sso_dhb_zero_1_1),
    REGISTER_APITEST(paddrpara, sso_dhb_zero_1_M),
    REGISTER_APITEST(paddrpara, sso_dhb_off_1_1),
    REGISTER_APITEST(paddrpara, sso_dhb_off_1_M),
    REGISTER_APITEST(paddrpara, sso_dpmrxt_int_1_1),
    REGISTER_APITEST(paddrpara, sso_dpmrxt_int_1_M),
    REGISTER_APITEST(paddrpara, sso_dav4_tos_1_1),
    REGISTER_APITEST(paddrpara, sso_dav4_tos_1_M),
    REGISTER_APITEST(paddrpara, sso_hb_demand_1_1),
    REGISTER_APITEST(paddrpara, sso_hb_demand_1_M),
    REGISTER_APITEST(defsend, gso_def_1_1),
    REGISTER_APITEST(defsend, gso_def_1_M),
    REGISTER_APITEST(defsend, sso_on_1_1),
    REGISTER_APITEST(defsend, sso_on_1_M),
    REGISTER_APITEST(defsend, sso_asc_1_1),
    REGISTER_APITEST(defsend, sso_asc_1_M),
    REGISTER_APITEST(defsend, sso_inherit_1_1),
    REGISTER_APITEST(defsend, sso_inherit_1_M),
    REGISTER_APITEST(defsend, sso_inherit_ncep_1_1),
    REGISTER_APITEST(defsend, sso_inherit_ncep_1_M),
    REGISTER_APITEST(defsend, sso_nc_other_asc_1_M),
    REGISTER_APITEST(events, gso_def_1_1),
    REGISTER_APITEST(events, gso_def_1_M),
    REGISTER_APITEST(events, sso_1_1),
    REGISTER_APITEST(events, sso_1_M),
    REGISTER_APITEST(mapped, gso_1_1_def),
    REGISTER_APITEST(mapped, gso_1_M_def),
    REGISTER_APITEST(mapped, sso_1_1),
    REGISTER_APITEST(mapped, sso_1_M),
    REGISTER_APITEST(mapped, sso_bad_1_1),
    REGISTER_APITEST(mapped, sso_bad_1_M),
    REGISTER_APITEST(maxseg, gso_def_1_1),
    REGISTER_APITEST(maxseg, sso_set_1_1),
    REGISTER_APITEST(maxseg, gso_def_1_M),
    REGISTER_APITEST(maxseg, sso_set_1_M),
    REGISTER_APITEST(maxseg, sso_asc_1_1),
    REGISTER_APITEST(maxseg, sso_asc_1_M),
    REGISTER_APITEST(maxseg, sso_inherit_1_1),
    REGISTER_APITEST(maxseg, sso_inherit_1_M),
    REGISTER_APITEST(maxseg, sso_inherit_ncep_1_1),
    REGISTER_APITEST(maxseg, sso_inherit_ncep_1_M),
    REGISTER_APITEST(maxseg, sso_nc_other_asc_1_M),
    REGISTER_APITEST(authchk, gso_1_1),
    REGISTER_APITEST(authchk, gso_1_M),
    REGISTER_APITEST(authchk, sso_1_1),
    REGISTER_APITEST(authchk, sso_1_M),
    REGISTER_APITEST(hmacid, sso_1_1),
    REGISTER_APITEST(hmacid, sso_1_M),
    REGISTER_APITEST(hmacid, sso_bad_1_1),
    REGISTER_APITEST(hmacid, sso_bad_1_M),
    REGISTER_APITEST(hmacid, sso_nosha1_1_1),
    REGISTER_APITEST(hmacid, sso_nosha1_1_M),
    REGISTER_APITEST(authkey, gso_def_1_1),
    REGISTER_APITEST(authkey, gso_def_1_M),
    REGISTER_APITEST(authkey, gso_new_1_1),
    REGISTER_APITEST(authkey, gso_new_1_M),
    REGISTER_APITEST(authkey, sso_def_1_1),
    REGISTER_APITEST(authkey, sso_def_1_M),
    REGISTER_APITEST(authkey, sso_new_1_1),
    REGISTER_APITEST(authkey, sso_new_1_M),
    REGISTER_APITEST(authkey, sso_newnul_1_1),
    REGISTER_APITEST(authkey, sso_newnul_1_M),
    REGISTER_APITEST(authkey, gso_a_def_1_1),
    REGISTER_APITEST(authkey, gso_a_def_1_M),
    REGISTER_APITEST(authkey, sso_a_def_1_1),
    REGISTER_APITEST(authkey, sso_a_def_1_M),
    REGISTER_APITEST(authkey, sso_a_new_1_1),
    REGISTER_APITEST(authkey, sso_a_new_1_M),
    REGISTER_APITEST(authkey, sso_a_newnul_1_1),
    REGISTER_APITEST(authkey, sso_a_newnul_1_M),
    REGISTER_APITEST(actkey, gso_def_1_1),
    REGISTER_APITEST(actkey, gso_def_1_M),
    REGISTER_APITEST(actkey, sso_def_1_1),
    REGISTER_APITEST(actkey, sso_def_1_M),
    REGISTER_APITEST(actkey, sso_inval_1_1),
    REGISTER_APITEST(actkey, sso_inval_1_M),
    REGISTER_APITEST(actkey, sso_new_1_1),
    REGISTER_APITEST(actkey, sso_new_1_M),
    REGISTER_APITEST(actkey, sso_inhdef_1_1),
    REGISTER_APITEST(actkey, sso_inhdef_1_M),
    REGISTER_APITEST(actkey, sso_inhnew_1_1),
    REGISTER_APITEST(actkey, sso_inhnew_1_M),
    REGISTER_APITEST(actkey, sso_achg_1_1),
    REGISTER_APITEST(actkey, sso_achg_1_M),
    REGISTER_APITEST(delkey, gso_def_1_1),
    REGISTER_APITEST(delkey, gso_def_1_M),
    REGISTER_APITEST(delkey, gso_inval_1_1),
    REGISTER_APITEST(delkey, gso_inval_1_M),
    REGISTER_APITEST(delkey, sso_def_1_1),
    REGISTER_APITEST(delkey, sso_def_1_M),
    REGISTER_APITEST(delkey, sso_inval_1_1),
    REGISTER_APITEST(delkey, sso_inval_1_M),
    REGISTER_APITEST(delkey, sso_new_1_1),
    REGISTER_APITEST(delkey, sso_new_1_M),
    REGISTER_APITEST(delkey, sso_newact_1_1),
    REGISTER_APITEST(delkey, sso_newact_1_M),
    REGISTER_APITEST(delkey, sso_zero_1_1),
    REGISTER_APITEST(delkey, sso_zero_1_M),
    REGISTER_APITEST(dsack, gso_def_1_1),
    REGISTER_APITEST(dsack, gso_def_1_M),
    REGISTER_APITEST(dsack, sso_delay_1_1),
    REGISTER_APITEST(dsack, sso_delay_1_M),
    REGISTER_APITEST(dsack, sso_freq_1_1),
    REGISTER_APITEST(dsack, sso_freq_1_M),
    REGISTER_APITEST(dsack, sso_asc_1_1),
    REGISTER_APITEST(dsack, sso_asc_1_M),
    REGISTER_APITEST(dsack, sso_inherit_1_1),
    REGISTER_APITEST(dsack, sso_inherit_1_M),
    REGISTER_APITEST(dsack, sso_inherit_ncep_1_1),
    REGISTER_APITEST(dsack, sso_inherit_ncep_1_M),
    REGISTER_APITEST(dsack, sso_nc_other_asc_1_M),
    REGISTER_APITEST(fraginter, gso_def_1_1),
    REGISTER_APITEST(fraginter, gso_def_1_M),
    REGISTER_APITEST(fraginter, sso_1_1),
    REGISTER_APITEST(fraginter, sso_1_M),
    REGISTER_APITEST(fraginter, sso_bad_1_1),
    REGISTER_APITEST(fraginter, sso_bad_1_M),
    REGISTER_APITEST(pdapi, gso_1_1),
    REGISTER_APITEST(pdapi, gso_1_M),
    REGISTER_APITEST(padapi, sso_1_1),
    REGISTER_APITEST(pdapi, sso_1_M),
    REGISTER_APITEST(xrcvinfo, sso_1_1),
    REGISTER_APITEST(xrcvinfo, sso_1_M),
    REGISTER_APITEST(aasconf, sso_1_1),
    REGISTER_APITEST(aasconf, sso_1_M),
    REGISTER_APITEST(maxburst, gso_def_1_1),
    REGISTER_APITEST(maxburst, gso_def_1_M),
    REGISTER_APITEST(maxburst, sso_1_1),
    REGISTER_APITEST(maxburst, sso_1_M),
    REGISTER_APITEST(context, sso_1_1),
    REGISTER_APITEST(context, sso_1_M),
    REGISTER_APITEST(context, sso_asc_1_1),
    REGISTER_APITEST(context, sso_asc_1_M),
    REGISTER_APITEST(context, sso_inherit_1_1),
    REGISTER_APITEST(context, sso_inherit_1_M),
    REGISTER_APITEST(context, sso_inherit_ncep_1_1),
    REGISTER_APITEST(context, sso_inherit_ncep_1_M),
    REGISTER_APITEST(context, sso_nc_other_asc_1_M),
    REGISTER_APITEST(eeor, sso_1_1),
    REGISTER_APITEST(eeor, sso_1_M),
    REGISTER_APITEST(read, status),
    REGISTER_APITEST(read, paddrinfo),
    REGISTER_APITEST(read, auth_p_chklist),
    REGISTER_APITEST(read, auth_l_chklist),
    REGISTER_APITEST(reuseport, set_1_to_M),
    REGISTER_APITEST(reuseport, get_1_to_M),
    REGISTER_APITEST(reuseport, set_before_bind),
    REGISTER_APITEST(reuseport, get_default),
    REGISTER_APITEST(reuseport, get_after_set),
    REGISTER_APITEST(reuseport, set_after_bind),
    REGISTER_APITEST(reuseport, set_after_bindx),
    REGISTER_APITEST(reuseport, bind_twice),
    REGISTER_APITEST(reuseport, bind_twice_illegal_1),
    REGISTER_APITEST(reuseport, bind_twice_illegal_2),
    REGISTER_APITEST(reuseport, bind_twice_listen),
    REGISTER_APITEST(reuseport, bind_subset),
    REGISTER_APITEST(reuseport, listen_twice),
    REGISTER_APITEST(reuseport, accept_inheritage),
    REGISTER_APITEST(reuseport, connect),
    REGISTER_APITEST(connect, non_listen),
    REGISTER_APITEST(connect, listen),
    REGISTER_APITEST(connect, self_non_listen),
    REGISTER_APITEST(connect, self_listen),
    REGISTER_APITEST(bind, port_s_a_s_p),
    REGISTER_APITEST(bind, v4tov6_s_a_s_p),
    REGISTER_APITEST(bind, v4tov6_w_a_s_p),
    REGISTER_APITEST(bind, v4tov6only_w_a),
    REGISTER_APITEST(bind, v4tov6only_s_a),
    REGISTER_APITEST(bind, same_port_s_a_s_p),
    REGISTER_APITEST(bind, duplicate_s_a_s_p),
    REGISTER_APITEST(bind, refinement),
    REGISTER_APITEST(bindx, port_w_a_w_p),
    REGISTER_APITEST(bindx, port_s_a_w_p),
    REGISTER_APITEST(bindx, port_w_a_s_p),
    REGISTER_APITEST(bindx, port_s_a_s_p),
    REGISTER_APITEST(bindx, zero_flag),
    REGISTER_APITEST(bindx, add_zero_addresses),
    REGISTER_APITEST(bindx, rem_zero_addresses),
    REGISTER_APITEST(bindx, add_zero_addresses_NULL),
    REGISTER_APITEST(bindx, rem_zero_addresses_NULL),
    REGISTER_APITEST(bindx, add_null_addresses),
    REGISTER_APITEST(bindx, rem_null_addresses),
    REGISTER_APITEST(bindx, dup_add_s_a_s_p),
    REGISTER_APITEST(bindx, rem_last_s_a_s_p),
    REGISTER_APITEST(bindx, rem_s_a_s_p),
    REGISTER_APITEST(shutdown, 1toM_RD),
    REGISTER_APITEST(shutdown, 1toM_WR),
    REGISTER_APITEST(shutdown, 1toM_RDWR),
    REGISTER_APITEST(shutdown, 1to1_not_connected),
    REGISTER_APITEST(socket, ipv4_1to1),
    REGISTER_APITEST(socket, ipv4_1toM),
    REGISTER_APITEST(socket, ipv6_1to1),
    REGISTER_APITEST(socket, ipv6_1toM),
};

unsigned int number_of_tests = sizeof(all_tests) / sizeof(all_tests[0]);

