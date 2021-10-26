<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Sign Up</title>

    <!-- Font Icon -->
    <link rel="stylesheet" href="<?=base_url('assets/frontend/signin/');?>fonts/material-icon/css/material-design-iconic-font.min.css">

    <!-- Main css -->
    <link rel="stylesheet" href="<?=base_url('assets/frontend/signin/');?>css/style.css">
    <link rel="stylesheet" href="<?=base_url('assets/frontend/signin/');?>css/bootstrap.min.css">
</head>
<style type="text/css">
   .error {
      color: red;
      background-color: #acf;
   }
   .d-none{
      display: none;
   }
      .nav-tabs .nav-link {
    border: 0px solid transparent;
  }   
  .nav-tabs .active {
    border: 1px solid transparent;
  }
</style>
<body>





    <div class="main">
        <!-- Sign up form -->
        <section class="signup">
            <div class="container">
                <div class="signup-content">
                    <div class="signup-form">
                        <h2 class="form-title">Sign up</h2>

                        <ul class="nav nav-tabs" id="myTab" role="tablist">
                          <li class="nav-item">
                            <a class="nav-link" id="home-tab" data-toggle="tab1" href="javascript:void(0);" role="tab" aria-controls="home" aria-selected="true">Step 1</a>
                          </li>
                          <li class="nav-item">
                            <a class="nav-link active" id="profile-tab" data-toggle="tab1" href="javascript:void(0);" role="tab" aria-controls="profile" aria-selected="false">Step 2</a>
                          </li>
                          <li class="nav-item">
                            <a class="nav-link" id="contact-tab" data-toggle="tab1" href="javascript:void(0);" role="tab" aria-controls="contact" aria-selected="false">Step 3</a>
                          </li>
                          <li class="nav-item">
                            <a class="nav-link" id="contact-tab" data-toggle="tab1" href="javascript:void(0);" role="tab" aria-controls="contact" aria-selected="false">Step 4</a>
                          </li>
                        </ul>
                        <div class="tab-content" id="myTabContent">
                          <div class="tab-pane fade show active" id="home" role="tabpanel" aria-labelledby="home-tab">
                            <?=form_open('user-signup-2', 'class="register-form mt-2" id="register-form" name="register-form"');?>
                            <?php $LAST_ID = $this->session->userdata('UL_LAST_ID_INSERTED');//kk($LAST_ID); ?>
                                <?php echo notification_message();?>
                                <div class="form-group">
                                  
                                    <label for="u_otp"><i class="zmdi zmdi-account material-icons-name"></i></label>

                                    <input type="hidden" name="ul_id" value="<?=$LAST_ID['ul_id']?>"/>
                                    <input type="hidden" name="ul_user_phone" value="<?=$LAST_ID['ul_user_phone']?>"/>
                                    <input type="hidden" name="ul_otp" value="<?=$LAST_ID['ul_otp']?>"/>
                                    <input type="text" name="u_otp" id="u_otp" placeholder="Enter OTP *" value="<?= set_value('u_otp') ?>"/>
                                </div>

                                <div class="form-group form-button">
                                    <input type="submit" name="signup2" id="signup2" class="form-submit" value="Register"/>
                                </div>
                            <?=form_close();?>
                          </div>
                        </div>

                    </div>
                    <div class="signup-image">
                        <figure><img src="<?=base_url('assets/frontend/signin/');?>images/signup-image.jpg" alt="sing up image"></figure>
                        <a href="<?=base_url('user');?>" class="signup-image-link">I am already member</a>
                    </div>
                </div>
            </div>
        </section>

    </div>

    <!-- JS -->
    <script src="<?=base_url('assets/frontend/signin/');?>vendor/jquery/jquery.min.js"></script>
    <script src="<?=base_url('assets/frontend/signin/');?>js/main.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
        <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.17.0/jquery.validate.min.js"></script>
    <script type="text/javascript">
        $(function(){
          $("form[name='register-form']").validate({
            rules :{
              u_otp:{
                required: true,
              }
            },
            messages :{}
          });
        });
    </script>
</body>
</html>